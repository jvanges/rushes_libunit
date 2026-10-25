/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:46:45 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:51:45 by mmichele         ###   ########.fr       */
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
	return (launch_tests(&testlist, "LIBUNIT BONUS"));
}
