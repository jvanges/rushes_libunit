/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:46:13 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 01:37:31 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <stdlib.h>
#include <unistd.h>

static t_unit_test	*unit_test_last(t_unit_test *ut)
{
	while (ut->next)
		ut = ut->next;
	return (ut);
}

static void	unit_test_free(t_unit_test **ut)
{
	t_unit_test	*curr;
	t_unit_test	*next;

	curr = *ut;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*ut = 0;
}

void	load_test(t_unit_test **ut, const char *title, int (*func)(void))
{
	t_unit_test	*new;
	t_unit_test	*last;

	new = malloc(sizeof(t_unit_test));
	if (!new)
	{
		write(0, "Malloc failed\n", 15);
		return ;
	}
	new->title = title;
	new->func = func;
	new->next = 0;
 	last = unit_test_last(*ut);
	last->next = new;
}

int	launch_tests(t_unit_test **ut)
{
	t_unit_test		*curr;
	unsigned int	total;
	unsigned int	passed;

	curr = *ut;
	total = 0;
	passed = 0;
	while (curr->next)
	{
		// TODO should be executed by a child (fork)
		passed += (curr->func() == 0);
		total++;
		curr = curr->next;
	}
	unit_test_free(ut);
	if (total != passed)
		return (-1);
	return (0);
}
