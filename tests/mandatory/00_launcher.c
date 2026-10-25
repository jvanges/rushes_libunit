/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:46:45 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 21:11:18 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_mandatory.h"

#include "libunit.h"

int	mandatory_launcher(void)
{
	t_unit_test	*testlist;

	testlist = 0;
	load_test(&testlist, "OK", &ok_test);
	load_test(&testlist, "KO", &ko_test);
	load_test(&testlist, "SIGSEGV", &sigsegv_test);
	load_test(&testlist, "SIGBUS", &sigbus_test);
	load_test(&testlist, "REAL SIGSEGV", &real_sigsegv_test);
	load_test(&testlist, "REAL SIGBUS", &real_sigbus_test);
	return (launch_tests(&testlist, "LIBUNIT MANDATORY"));
}
