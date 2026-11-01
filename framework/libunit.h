/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:04:34 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:19:21 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

/* Maillon de la liste chaînée des tests :
** - title : nom du test, affiché avant son verdict
** - func  : pointeur sur la fonction de test (0 = succès, autre = échec)
** - next  : maillon suivant (NULL en fin de liste)
*/
typedef struct s_unit_test
{
	const char			*title;
	int					(*func)(void);
	struct s_unit_test	*next;
}	t_unit_test;

/* unit_test.c — API publique du framework */
/* load_test    : ajoute un test en fin de liste */
/* launch_tests : exécute tous les tests, affiche le résumé, libère la liste.
**              Retourne 0 si tous les tests passent, -1 sinon. */
void		load_test(t_unit_test **ut, const char *title, int (*func)(void));
int			launch_tests(t_unit_test **ut, const char *func_name);

/* exec_test.c — interne : fork le test dans un enfant, analyse sa mort */
int			exec_func(t_unit_test *ut, const char *func_name);

/* print_res.c print_res_bonus.c — affichage des verdicts */
int			print_res(int status);
void		print_sig(int sig);
int			print_timeout(void);

/* child_proc.c child_proc_bonus.c — code exécuté DANS l'enfant forké */
int			child_proc(t_unit_test *ut, const char *func_name);

#endif // LIBUNIT_H