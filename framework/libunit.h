/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:04:34 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 01:35:54 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

typedef struct s_unit_test
{
	const char			*title;
	int					(*func)(void);
	struct s_unit_test	*next;
}	t_unit_test;

void	load_test(t_unit_test **ut, const char *title, int (*func)(void));
int		launch_tests(t_unit_test **ut);

#endif // LIBUNIT_H