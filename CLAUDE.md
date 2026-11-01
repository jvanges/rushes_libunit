# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Contexte

Rush **libunit** de 42 (projet de groupe, **déjà rendu**) : une micro-librairie de tests
unitaires en C. `SOUTENANCE.md` (à la racine) contient une documentation détaillée du
fonctionnement, rédigée pour préparer la défense du projet — la lire avant de répondre
à des questions sur l'architecture ou de modifier du code. Les commentaires du code sont
en français, à visée pédagogique.

## Commandes

Trois Makefiles indépendants, un par dossier (`framework/`, `tests/`, `real-tests/`) :

```sh
make -C framework            # libunit.a (mandatory)
make -C framework bonus      # version bonus, copiée PAR-DESSUS libunit.a

make -C tests                # binaire 'tests' (tests DU framework, mandatory)
make -C tests test           # compile + exécute ./tests
make -C tests bonus          # binaire 'tests_bonus', copié sur 'tests'

make -C real-tests           # tests de vraies fonctions (strlen, atoi)
make -C real-tests bonus     # ajoute les tests printf
```

Les Makefiles de `tests/` et `real-tests/` compilent eux-mêmes `framework/` et `libft/`
(cible `lib`), pas besoin de les builder à la main avant.

⚠️ **Un exit code 255 est normal** dans `tests/` : les tests y sont *censés* échouer
(ils provoquent KO, SIGSEGV, SIGBUS, timeout...). Sortie attendue : `1/6` (mandatory),
`0/11` (bonus). Un `make test` qui échoue avec `Error 255` n'est PAS un bug.

Pas de lanceur de test unitaire individuel : pour tester un seul cas, créer un petit
main qui n'appelle que `load_test` + `launch_tests` sur ce test.

## Architecture

### Les trois couches

1. **`framework/`** → `libunit.a`. API publique réduite à deux fonctions :
   `load_test()` (ajoute un test en fin de liste chaînée `t_unit_test`) et
   `launch_tests()` (exécute tout, libère la liste, renvoie 0 si tout passe).
2. **`tests/`** → vérifie le framework lui-même : chaque test provoque un verdict
   précis (`raise(SIGSEGV)`, vrai déréférencement NULL, mmap piégé pour SIGBUS...).
3. **`real-tests/`** → démonstration client : compare libc vs libft
   (`strlen`/`ft_strlen`, `atoi`/`ft_atoi`, `printf`/`ft_printf`).

Convention partout : un test renvoie **0 = succès, toute autre valeur = échec**.

### La mécanique centrale (exec_test.c)

Chaque test tourne dans un enfant `fork()` : un crash tue l'enfant, pas le framework.
Le parent fait `wait(&status)` puis distingue `WIFEXITED` (`WEXITSTATUS` → OK/KO) de
`WIFSIGNALED` (`WTERMSIG` →quel signal). Le retour du test traverse la frontière des
processus via le code d'`exit()`.

### L'astuce mandatory / bonus

`unit_test.c` est commun ; les trois autres fichiers existent en deux versions protégées
par `#ifndef BONUS` / `#ifdef BONUS` (fichiers entiers). `make bonus` ajoute `-D BONUS`,
les versions mandatory compilent en objets vides, et l'archive bonus est **copiée sur le
même nom** `libunit.a` — les clients gardent `-lunit` inchangé.

### Les spécificités du bonus (child_proc_bonus.c)

- **Timeout** : `alarm(5)` dans l'enfant → mort par `SIGALRM` → `[TIMEOUT]`.
- **Vérification stdout** : `dup2` de stdout vers un `tmpfile`, puis comparaison des
  **deux moitiés** de la sortie capturée (`memcmp`). Pensé pour les tests printf qui
  écrivent `printf(...)` puis `ft_printf(...)` : `[sortie printf][sortie ft_printf]`.
  Les tests écrivant sur stdout doivent donc toujours produire une sortie en deux
  moitiés identiques.
- **Logs** : `exec_test_bonus.c` chronomètre (`gettimeofday`) et écrit dans
  `<fonction>.log` en `O_APPEND` (fichiers `.log` générés à côté des binaires, inoffensifs).
- Affichage couleur via `ft_aec_print` (extension de la `libft/` locale).
