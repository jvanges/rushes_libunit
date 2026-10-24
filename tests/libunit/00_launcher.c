/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:46:45 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 12:03:33 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libunit.h"

#include "libunit.h"

int	libunit_launcher(void)
{
	t_unit_test	*testlist;

	testlist = 0;
	load_test(&testlist, "OK", &ok_test);
	load_test(&testlist, "KO", &ko_test);
	load_test(&testlist, "SIGSEGV", &sigsegv_test);
	load_test(&testlist, "SIGBUS", &sigbus_test);
	return (launch_tests(&testlist, "LIBUNIT"));
}
