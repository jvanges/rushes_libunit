/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:46:45 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 21:22:35 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"

#include "libunit.h"

int	bonus_launcher(void)
{
	t_unit_test	*testlist;

	testlist = 0;
	load_test(&testlist, "SIGABRT", &sigabrt_test);
	load_test(&testlist, "SIGFPE", &sigfpe_test);
	load_test(&testlist, "SIGPIPE", &sigpipe_test);
	load_test(&testlist, "SIGILL", &sigill_test);
	load_test(&testlist, "TIMEOUT", &timeout_test);
	load_test(&testlist, "REAL SIGABRT", &real_sigabrt_test);
	load_test(&testlist, "REAL SIGFPE", &real_sigfpe_test);
	load_test(&testlist, "REAL SIGPIPE", &real_sigpipe_test);
	load_test(&testlist, "REAL SIGILL", &real_sigill_test);
	load_test(&testlist, "REAL TIMEOUT", &real_timeout_test);
	load_test(&testlist, "INVALID STDOUT", &stdout_test);
	return (launch_tests(&testlist, "LIBUNIT_BONUS"));
}
