/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 02:05:14 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:19:07 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <stdlib.h>	// malloc free

#include "libft.h"	// ft_printf

/* Renvoie le dernier maillon de la liste (pour ajouter en fin). */
static t_unit_test	*unit_test_last(t_unit_test *ut)
{
	while (ut && ut->next)
		ut = ut->next;
	return (ut);
}

/* Libère toute la liste et remet le pointeur de tête à NULL.
** Appelée par launch_tests dans le PARENT une fois les tests exécutés. */
static void	unit_test_free(t_unit_test **ut)
{
	t_unit_test	*curr;
	t_unit_test	*next;

	if (!ut)
		return ;
	curr = *ut;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*ut = NULL;
}

/* Ajoute un test EN FIN de liste : les tests s'exécutent dans
** l'ordre de chargement. En cas de paramètre NULL ou d'échec de
** malloc, le test est ignoré (message sur stderr) sans tout casser. */
void	load_test(t_unit_test **ut, const char *title, int (*func)(void))
{
	t_unit_test	*new;
	t_unit_test	*last;

	if (!ut || !title || !func)
		return ;
	new = malloc(sizeof(t_unit_test));
	if (!new)
	{
		ft_dprintf(2, "malloc failed\n");
		return ;
	}
	new->title = title;
	new->func = func;
	new->next = NULL;
	if (!*ut)
		*ut = new;
	else
	{
		last = unit_test_last(*ut);
		last->next = new;
	}
}

/* Cœur de la boucle : pour chaque test, on affiche son nom puis on
** l'exécute dans un enfant via exec_func. Seul un retour == 0 compte
** comme réussi. La liste est libérée avant le résumé.
** Retour : 0 si tout a passé, -1 sinon (propagé par le main). */
int	launch_tests(t_unit_test **ut, const char *func_name)
{
	t_unit_test		*curr;
	unsigned int	total;
	unsigned int	passed;

	if (!ut)
		return (-1);
	curr = *ut;
	total = 0;
	passed = 0;
	while (curr)
	{
		ft_printf("%s: %s: ", func_name, curr->title);
		passed += (exec_func(curr, func_name) == 0);
		total++;
		curr = curr->next;
	}
	unit_test_free(ut);
	ft_printf("%d/%d tests checked\n\n", passed, total);
	if (total != passed)
		return (-1);
	return (0);
}
