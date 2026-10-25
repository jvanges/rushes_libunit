/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:30:42 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 11:30:16 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_strlen.h"

#include "libunit.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = 0;
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "NULL test", &null_test);
	load_test(&testlist, "Bigger string test", &bigger_str_test);
	load_test(&testlist, "Empty string test", &empty_test);
	load_test(&testlist, "Embedded NULL test", &embedded_null_test);
	load_test(&testlist, "Special characters test", &special_characters_test);
	load_test(&testlist, "Multiple strings test", &multiple_strings_test);
	return (launch_tests(&testlist, "STRLEN"));
}
