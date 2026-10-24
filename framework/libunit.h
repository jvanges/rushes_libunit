/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:04:34 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 11:27:37 by mmichele         ###   ########.fr       */
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

/* unit_test.c */
void		load_test(t_unit_test **ut, const char *title, int (*func)(void));
int			launch_tests(t_unit_test **ut, const char *func_name);

/* exec_test.c */
int			exec_func(t_unit_test *ut);

/* print_res.c print_res_bonus.c */
int			print_res(int status);
void		print_sig(int sig);

#endif // LIBUNIT_H