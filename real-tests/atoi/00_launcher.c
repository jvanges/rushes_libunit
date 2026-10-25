/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:34:00 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 14:53:32 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_atoi.h"

#include "libunit.h"

int	atoi_launcher(void)
{
	t_unit_test	*testlist;

	testlist = 0;
	load_test(&testlist, "Basic test", &atoi_basic_test);
	load_test(&testlist, "Whitespace and sign test", &atoi_whitespace_test);
	load_test(&testlist, "Invalid characters test",
		&atoi_invalid_characters_test);
	load_test(&testlist, "Integer limits test", &atoi_limits_test);
	load_test(&testlist, "Integer null pointer test", &atoi_null_test);
	load_test(&testlist, "Trailing whitespace test",
		&atoi_trailing_whitespace_test);
	load_test(&testlist, "Sign position test", &atoi_sign_position_test);
	load_test(&testlist, "Zero values test", &atoi_zero_values_test);
	return (launch_tests(&testlist, "ATOI"));
}
