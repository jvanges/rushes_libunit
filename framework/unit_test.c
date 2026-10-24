/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 02:05:14 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 20:11:04 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <stdlib.h>	// malloc free

#include "libft.h"	// ft_printf

static t_unit_test	*unit_test_last(t_unit_test *ut)
{
	while (ut && ut->next)
		ut = ut->next;
	return (ut);
}

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
		passed += (exec_func(curr) == 0);
		total++;
		curr = curr->next;
	}
	unit_test_free(ut);
	ft_printf("%d/%d tests checked\n\n", passed, total);
	if (total != passed)
		return (-1);
	return (0);
}
