# Libunit — Document de préparation à la soutenance

> Projet de groupe (rush) — librairie de tests unitaires en C.
> Projet déjà rendu : ce document sert uniquement à préparer la défense.

---

## Table des matières

1. [Le concept général](#1-le-concept-général)
2. [Architecture du dépôt](#2-architecture-du-dépôt)
3. [Cycle de vie d'un test (la mécanique centrale)](#3-cycle-de-vie-dun-test)
4. [Le framework, fichier par fichier](#4-le-framework-fichier-par-fichier)
5. [Les bonus](#5-les-bonus)
6. [L'astuce de build mandatory / bonus](#6-lastuce-de-build-mandatory--bonus)
7. [tests/ — le framework teste le framework](#7-tests--le-framework-teste-le-framework)
8. [real-tests/ — démonstration sur du vrai code](#8-real-tests--démonstration-sur-du-vrai-code)
9. [Mémo des appels système](#9-mémo-des-appels-système)
10. [Questions probables du correcteur](#10-questions-probables-du-correcteur)
11. [Sortie attendue](#11-sortie-attendue)

---

## 1. Le concept général

**libunit** est une micro-librairie de tests unitaires. Le contrat :

1. L'utilisateur **charge** des tests dans une liste chaînée avec `load_test()`
2. Il lance toute la suite avec `launch_tests()`
3. Chaque test est exécuté dans un **processus enfant** (`fork()`), pour qu'un crash
   (segfault, bus error, timeout...) ne tue pas le framework lui-même
4. Le parent analyse **comment l'enfant est mort** et affiche un verdict :
   `[OK]`, `[KO]`, `[SIGSEGV]`, `[SIGBUS]`, `[TIMEOUT]`...

**Convention de retour d'un test : `0` = succès, toute autre valeur = échec.**

Le point fondamental à comprendre : *la valeur de retour du test traverse la frontière
entre deux processus*. Le test écrit `return 0` ou `return -1`, l'enfant fait
`exit(ce_retour)`, le parent récupère ce code via `wait(&status)`.

---

## 2. Architecture du dépôt

```
rushes_libunit/
├── framework/      → la librairie elle-même, compilée en libunit.a
│   ├── libunit.h            structure + prototypes publics
│   ├── unit_test.c          load_test / launch_tests (commun aux deux versions)
│   ├── exec_test.c          fork + wait + analyse du status (mandatory)
│   ├── child_proc.c         code exécuté dans l'enfant (mandatory)
│   ├── print_res.c          affichage des verdicts (mandatory)
│   ├── exec_test_bonus.c    + logs horodatés .log
│   ├── child_proc_bonus.c   + timeout (alarm) + capture stdout
│   ├── print_res_bonus.c    + couleurs ANSI + signaux supplémentaires
│   └── Makefile
├── libft/          → la libft du groupe (ft_printf, ft_dprintf, ft_aec_print...)
├── tests/          → tests DU framework (vérifie chaque verdict)
│   ├── mandatory/  → OK, KO, SIGSEGV, SIGBUS, vrais segfault/bus error
│   ├── bonus/      → SIGABRT, SIGFPE, SIGPIPE, SIGILL, TIMEOUT, stdout invalide
│   └── Makefile    → produit le binaire `tests`
└── real-tests/     → tests de VRAIES fonctions, comparant libc vs libft
    ├── strlen/     → strlen vs ft_strlen (7 tests)
    ├── atoi/       → atoi vs ft_atoi (8 tests)
    ├── printf/     → printf vs ft_printf (15 tests, bonus uniquement)
    └── Makefile    → produit le binaire `tests`
```

Trois niveaux : la **librairie**, les **tests de la librairie**, les **tests réels**
écrits *avec* la librairie.

---

## 3. Cycle de vie d'un test

```
main()
  └── launcher (ex: strlen_launcher)
        ├── load_test(&list, "Basic test", &basic_test)   ← remplit la liste chaînée
        ├── load_test(&list, "NULL test",  &null_test)
        └── launch_tests(&list, "STRLEN")
              │  pour chaque nœud de la liste :
              │    affiche "STRLEN: Basic test: "
              └──► exec_func(node)
                     │
                     ├── fork() ──────────────┬──────────────────────────
                     │                        │                          │
                     │  PARENT (pid > 0)      │   ENFANT (pid == 0)      │
                     │                        │                          │
                     │  wait(&status) ◄───────┼── exit(child_proc())     │
                     │        │               │        └── ut->func()    │
                     │        │               │             (LE TEST)    │
                     │        │               │                          │
                     │  ◄─────┴──────── mort de l'enfant                 │
                     │        │                                          │
                     │  WIFEXITED(status) ? ──oui──► WEXITSTATUS(status) │
                     │        │                        0 → [OK]          │
                     │        non                      ≠0 → [KO]         │
                     │        │                                          │
                     │  WIFSIGNALED(status) ? ──oui──► WTERMSIG(status)  │
                     │                             SIGSEGV → [SIGSEGV]   │
                     │                             SIGBUS  → [SIGBUS]    │
                     │                             SIGALRM → [TIMEOUT]   │
                     │
              ├── libère toute la liste (unit_test_free)
              ├── affiche "X/Y tests checked"
              └── retourne 0 si tout a passé, -1 sinon
```

**Pourquoi fork ?** Un segfault tue le *processus entier*. Sans fork, le premier test
qui crashe arrêterait toute la suite (et le framework). Avec fork, c'est l'enfant qui
meurt ; le parent survit, rapporte le signal, et enchaîne sur le test suivant.

---

## 4. Le framework, fichier par fichier

### 4.1 `libunit.h` — la structure

```c
typedef struct s_unit_test
{
	const char			*title;  /* nom affiché du test            */
	int					(*func)(void); /* pointeur sur la fonction */
	struct s_unit_test	*next;   /* maillon suivant                */
}	t_unit_test;
```

Liste chaînée simple. Seules deux fonctions sont réellement publiques pour
l'utilisateur : `load_test` et `launch_tests`.

### 4.2 `unit_test.c` — gestion de la liste

**`load_test(t_unit_test **ut, const char *title, int (*func)(void))`**
- `malloc` d'un nouveau nœud, stockage du titre et du pointeur de fonction
- ajout **en fin de liste** → les tests s'exécutent dans l'ordre de chargement
- garde-fous : paramètres NULL ou échec malloc → message sur stderr, abandon propre

**`launch_tests(t_unit_test **ut, const char *func_name)`**
- parcourt la liste ; affiche `<func_name>: <title>: ` puis appelle `exec_func`
- `passed += (exec_func(...) == 0);` — seul un retour **exactement 0** compte
- **libère toute la liste** (`unit_test_free`) avant le résumé → pas de fuite côté parent
- affiche `<passed>/<total> tests checked`
- retourne 0 si tout a passé, -1 sinon (le `main` propage ce -1 → exit code 255)

> Le parent détient et libère la liste. Les enfants forkés en héritent d'une **copie**
> (mémoire copiée au fork), mais ils meurent aussitôt — aucune fuite à gérer de leur côté.

### 4.3 `exec_test.c` — fork + wait (cœur du projet)

```c
pid = fork();
if (pid == -1)                  /* échec du fork              */
	return (-1);
else if (pid == 0)              /* ENFANT                     */
	exit(child_proc(ut, func_name));
else                            /* PARENT : attend l'enfant   */
	wait(&status);

if (WIFEXITED(status))                       /* exit() normal */
	return (print_res(WEXITSTATUS(status))); /* → [OK] / [KO] */
else if (WIFSIGNALED(status))                /* tué par signal */
	print_sig(WTERMSIG(status));             /* → [SIGSEGV]... */
return (-1);
```

Les trois branches de `fork()` :
| Valeur de `pid` | Qui | Action |
|---|---|---|
| `-1` | parent | erreur (plus de processus disponibles) |
| `0` | **enfant** | exécute le test puis `exit(son_retour)` |
| `> 0` | **parent** | `wait(&status)` bloque jusqu'à la mort de l'enfant |

### 4.4 `child_proc.c` — version mandatory

```c
int	child_proc(t_unit_test *ut, const char *func_name)
{
	(void)func_name;
	return (ut->func());   /* exécute le test, son retour devient le exit code */
}
```

Trivial en mandatory : toute la logique supplémentaire est en bonus.

### 4.5 `print_res.c` — les verdicts

```c
int	print_res(int status)
{
	if (status == 0)
		ft_printf("[OK]\n");
	else
		ft_printf("[KO]\n");
	return (-!!status);   /* 0 si status==0, -1 sinon */
}
```

**`-!!status`** : la double négation normalise n'importe quel entier en `0` ou `1`.
Donc `print_res` renvoie `0` (succès) ou `-1` (échec) — exactement la convention
attendue par `launch_tests` qui teste `== 0`.

`print_sig` ne connaît que `SIGSEGV` et `SIGBUS` en mandatory (exigence du sujet).

---

## 5. Les bonus

### 5.1 Le timeout — `child_proc_bonus.c`

```c
alarm(5);               /* le noyau enverra SIGALRM à CE processus dans 5 s */
status = ut->func();    /* si le test boucle, il est tué par SIGALRM        */
```

Si le test boucle à l'infini, au bout de 5 secondes le noyau envoie `SIGALRM`
**à l'enfant**, qui meurt. Le parent voit `WIFSIGNALED` + `WTERMSIG == SIGALRM`
→ affiche `[TIMEOUT]` (magenta).

⚠️ **Question quasi certaine : l'alarme est posée dans l'enfant, pas dans le parent.**
Sinon c'est le framework lui-même qui serait interrompu.

### 5.2 La vérification de stdout — le mécanisme le plus subtil

Toujours dans `child_proc_bonus` :

```c
output = tmpfile();                            /* fichier temporaire anonyme   */
fflush(stdout);                                /* vide les buffers stdio       */
dup2(fileno(output), STDOUT_FILENO);           /* stdout → fichier temporaire  */
status = ut->func();                           /* le test écrit... dans output */
same_output = output_is_identical(output);     /* compare les deux moitiés     */
fclose(output);
if (status != 0 || !same_output)
	return (-1);
```

**Pourquoi comparer les deux moitiés ?** Regarde un test printf :

```c
if (printf("%c\n", 'A') == ft_printf("%c\n", 'A'))
```

Le test écrit **d'abord la sortie du vrai printf, puis celle de ft_printf**.
Tout est capturé dans le fichier :

```
[ sortie de printf ][ sortie de ft_printf ]
└──── 1re moitié ───┘└──── 2nde moitié ────┘
```

`output_is_identical()` fait `memcmp(content, content + half_length, half_length)` :
si les deux moitiés sont égales, les sorties correspondent. Le test vérifie donc
**à la fois la valeur de retour ET le contenu affiché**.

Les garde-fous de `output_is_identical` :
- `fflush(stdout)` avant lecture : stdout est **bufferisé**, sinon le contenu
  resterait dans le buffer stdio au lieu du fichier
- `length % 2 != 0` : une longueur impaire ne peut pas être deux moitiés égales
- `fseek` en fin (pour `ftell` = mesurer) puis retour au début (pour relire)

C'est validé par `tests/bonus/11_stdout_test.c` : `write(1, "abc", 4); write(1, "def", 4);`
écrit 8 octets dont les moitiés `abc\0` / `def\0` diffèrent → verdict `[KO]` attendu
(le test s'appelle « INVALID STDOUT »).

### 5.3 Les logs horodatés — `exec_test_bonus.c`

- `gettimeofday` avant le fork et après le wait
- `file_logger` écrit dans `<func_name>.log` (ex. `STRLEN.log`), ouvert en `O_APPEND`
  (les runs s'accumulent) :
  - nom du test
  - timestamp début/fin (formatés via `localtime`)
  - durée en secondes.microsecondes

### 5.4 L'affichage en couleur — `print_res_bonus.c`

`ft_aec_print` (extension de la libft) émet des codes ANSI de couleur *(aec = ANSI
Escape Code)* : `[OK]` vert, `[KO]` rouge, signaux jaunes, `[TIMEOUT]` magenta.
Signaux gérés : SIGSEGV, SIGBUS, SIGABRT, SIGFPE, SIGPIPE, SIGILL, SIGALRM.

---

## 6. L'astuce de build mandatory / bonus

Dans `framework/Makefile` :

```make
SRCS        = unit_test.c exec_test.c       print_res.c       child_proc.c
BONUS_SRCS  = unit_test.c exec_test_bonus.c print_res_bonus.c child_proc_bonus.c

bonus: FLGS += -D BONUS          # ajoute le define BONUS à la compilation
...
$(BONUS_NAME): $(BONUS_OBJS)
	ar rcs $@ $^
	cp $@ $(NAME)                # libunit_bonus.a est COPIÉE sur libunit.a
```

Combiné aux gardes dans les sources :

```c
/* child_proc.c */       #ifndef BONUS   ... tout le fichier ...   #endif
/* child_proc_bonus.c */ #ifdef  BONUS   ... tout le fichier ...   #endif
```

→ En compilation `-D BONUS`, les fichiers mandatory produisent des **objets vides** :
impossible d'avoir deux définitions du même symbole (`child_proc` existe soit dans
l'un, soit dans l'autre, jamais les deux).

→ Comme l'archive bonus est copiée **sur le même nom** `libunit.a`, les clients
(`tests/`, `real-tests/`) gardent leur `-lunit` inchangé. C'est la retranscription
fidèle de la règle du sujet : *« make bonus pour compiler avec les fonctionnalités
bonus »*, sans forcer l'utilisateur à changer son édition de liens.

Même mécanique dans les Makefiles de `tests/` et `real-tests/` : le binaire
`tests_bonus` est copié sur `tests`.

---

## 7. tests/ — le framework teste le framework

Chaque test a pour seul but de **provoquer un verdict précis**.

### mandatory (`tests/mandatory/`)

| Test | Code | Verdict attendu |
|---|---|---|
| `ok_test` | `return 0` | `[OK]` |
| `ko_test` | `return -1` | `[KO]` |
| `sigsegv_test` | `raise(SIGSEGV)` | `[SIGSEGV]` |
| `sigbus_test` | `raise(SIGBUS)` | `[SIGBUS]` |
| `real_sigsegv_test` | déréférence un pointeur NULL (`volatile`) | `[SIGSEGV]` |
| `real_sigbus_test` | mmap de 8192 octets sur un fichier d'1 octet, lecture à l'offset 4096 | `[SIGBUS]` |

- `raise(sig)` : le processus s'envoie le signal à lui-même — mort « par signal »
  garantie, chemin `WIFSIGNALED` identique à un vrai crash.
- `real_sigbus_test` est un cas d'école : le mapping est valide (8192 octets
  mappés avec succès), mais la page visée n'a **pas de données derrière** dans le
  fichier → le matériel/MM envoie `SIGBUS`. C'est la différence avec `SIGSEGV`
  (adresse **hors de tout mapping** valide).

### bonus (`tests/bonus/`)

Même principe pour SIGABRT (`abort`), SIGFPE (division entière par zéro),
SIGPIPE (write sur un pipe sans lecteur), SIGILL (instruction machine illégale),
chacun en version `raise()` et en version « réelle », plus TIMEOUT (boucle infinie
tuée par `alarm`) et le test stdout invalide vu plus haut.

**Tous ces tests sont CENSÉS échouer** sauf `ok_test` : la sortie attendue est
`1/6` puis `0/11`. Le `main` renvoie donc `-1` → exit code 255 → `make test`
affiche `Error 255`. C'est normal et voulu.

---

## 8. real-tests/ — démonstration sur du vrai code

- **strlen** : 7 tests comparant `strlen` vs `ft_strlen` (chaîne classique, vide,
  NULL — qui segfaulte et prouve que le framework le rapporte, caractères spéciaux...)
- **atoi** : 8 tests comparant `atoi` vs `ft_atoi` (espaces, signes, limites
  INT_MAX/INT_MIN, NULL, zéros...)
- **printf** (bonus uniquement) : 15 tests comparant valeur de retour **et** sortie
  capturée de `printf` vs `ft_printf` — c'est là que la capture stdout du bonus
  prend tout son sens.

Chaque famille suit le pattern imposé par le sujet :
`00_launcher.c` + tests numérotés `01_...c`, `02_...c` + un header `tests_<fn>.h`.

---

## 9. Mémo des appels système

| Appel | Rôle ici |
|---|---|
| `fork()` | duplique le processus ; retourne 0 dans l'enfant, le pid de l'enfant dans le parent, -1 en erreur |
| `wait(&status)` | bloque jusqu'à la mort d'un enfant ; remplit `status` |
| `WIFEXITED(status)` | vrai si l'enfant s'est terminé par `exit()` |
| `WEXITSTATUS(status)` | le code passé à `exit()` (8 bits de poids faible) |
| `WIFSIGNALED(status)` | vrai si l'enfant a été tué par un signal |
| `WTERMSIG(status)` | le numéro du signal qui l'a tué |
| `raise(sig)` | s'envoie un signal à soi-même |
| `alarm(n)` | le noyau enverra SIGALRM au processus dans n secondes |
| `tmpfile()` | fichier temporaire anonyme, supprimé automatiquement à la fermeture |
| `dup2(old, new)` | fait pointer le descripteur `new` vers le même fichier que `old` |
| `fflush()` | force l'écriture des buffers stdio |
| `mmap()` | projette un fichier en mémoire ; lire au-delà de la fin réelle du fichier → SIGBUS |
| `gettimeofday()` | heure précise à la microseconde (pour les logs de durée) |

---

## 10. Questions probables du correcteur

1. **Pourquoi fork ?**
   Un test qui segfaulte tuerait tout le framework. Avec fork, c'est l'enfant qui
   meurt ; le parent survit, rapporte le signal et enchaîne.

2. **Comment distingues-tu un exit d'un signal ?**
   `wait` remplit `status`. `WIFEXITED` → `WEXITSTATUS` donne le code de retour.
   `WIFSIGNALED` → `WTERMSIG` donne le numéro du signal.

3. **Comment fonctionne le timeout ? Pourquoi l'alarme est-elle dans l'enfant ?**
   `alarm(5)` dans l'enfant ; le noyau envoie SIGALRM à l'enfant qui meurt ;
   le parent voit un enfant « tué par signal SIGALRM » et affiche `[TIMEOUT]`.
   Si l'alarme était dans le parent, elle interromprait le framework lui-même
   (et `wait` serait interrompu par un signal, autre problème).

4. **Comment vérifies-tu la sortie de ft_printf ?**
   `dup2` redirige stdout de l'enfant vers un `tmpfile` ; après le test, le fichier
   contient `[sortie printf][sortie ft_printf]` et on compare les deux moitiés avec
   `memcmp`.

5. **Pourquoi `fflush(stdout)` avant le `dup2` ?**
   stdout est bufferisé par stdio. Sans fflush, des données déjà écrites dans le
   buffer seraient perdues ou écrites au mauvais endroit après redirection
   (et le buffer est dupliqué dans l'enfant au fork).

6. **Où et quand la liste est-elle libérée ?**
   Dans `launch_tests`, par le parent, après la boucle d'exécution
   (`unit_test_free`), avant l'affichage du résumé.

7. **Que vaut `-!!status` dans `print_res` ?**
   `!!` normalise en 0 ou 1 ; le `-` donne 0 ou -1 : la convention de retour
   attendue par `launch_tests`.

8. **Pourquoi `make test` affiche-t-il Error 255 ?**
   Des tests ont échoué (c'est voulu dans `tests/`), `launch_tests` renvoie -1,
   `main` renvoie -1, tronqué à 255 en code de sortie (8 bits).

9. **Différence SIGSEGV / SIGBUS ?**
   SIGSEGV : adresse hors de tout mapping valide (ex. pointeur NULL).
   SIGBUS : adresse DANS un mapping valide mais sans données accessibles derrière
   (ex. page d'un mmap au-delà de la fin réelle du fichier).

10. **Comment le bonus remplace-t-il le mandatory sans casser les clients ?**
    Macros `#ifdef BONUS` : les deux implémentations ne coexistent jamais.
    L'archive bonus est copiée sur `libunit.a` → même `-lunit` côté clients.

11. **Que se passe-t-il si `fork()` échoue ? Et `wait()` ? Et `malloc()` ?**
    Chaque échec est détecté : message d'erreur sur stderr (`ft_dprintf(2, ...)`)
    et le test est compté comme raté, la suite continue.

---

## 11. Sortie attendue

`tests/` (mandatory) :

```
LIBUNIT_MANDATORY: OK: [OK]
LIBUNIT_MANDATORY: KO: [KO]
LIBUNIT_MANDATORY: SIGSEGV: [SIGSEGV]
LIBUNIT_MANDATORY: SIGBUS: [SIGBUS]
LIBUNIT_MANDATORY: REAL SIGSEGV: [SIGSEGV]
LIBUNIT_MANDATORY: REAL SIGBUS: [SIGBUS]
1/6 tests checked
```

`tests/` (bonus, en couleur) : les mêmes 6, puis

```
LIBUNIT_BONUS: SIGABRT: [SIGABRT]
LIBUNIT_BONUS: SIGFPE: [SIGFPE]
LIBUNIT_BONUS: SIGPIPE: [SIGPIPE]
LIBUNIT_BONUS: SIGILL: [SIGILL]
LIBUNIT_BONUS: TIMEOUT: [TIMEOUT]
LIBUNIT_BONUS: REAL SIGABRT: [SIGABRT]
LIBUNIT_BONUS: REAL SIGFPE: [SIGFPE]
LIBUNIT_BONUS: REAL SIGPIPE: [SIGPIPE]
LIBUNIT_BONUS: REAL SIGILL: [SIGILL]
LIBUNIT_BONUS: REAL TIMEOUT: [TIMEOUT]
LIBUNIT_BONUS: INVALID STDOUT: [KO]
0/11 tests checked
```

`real-tests/` : les tests strlen/atoi/printf — les verdicts dépendent de la
correction de la libft du groupe (idéalement tout `[OK]`, sauf les tests NULL
qui doivent donner `[SIGSEGV]`).

> Seuls les compteurs `passed` comptent un test qui renvoie **exactement 0** :
> les crashs et échecs ne sont pas des erreurs du framework, ils *sont* le résultat
> attendu.
