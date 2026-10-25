/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 12:50:00 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:24:03 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_printf.h"
#include "libunit.h"

int	printf_launcher(void)
{
	t_unit_test	*testlist;

	testlist = 0;
	load_test(&testlist, "Character conversion test", &printf_basic_test);
	load_test(&testlist, "String conversion test", &printf_string_test);
	load_test(&testlist, "Decimal conversion test", &printf_integer_test);
	load_test(&testlist, "Unsigned conversion test", &printf_unsigned_test);
	load_test(&testlist, "Pointer conversion test", &printf_pointer_test);
	load_test(&testlist, "Lowercase hexadecimal test", &printf_hex_lower_test);
	load_test(&testlist, "Uppercase hexadecimal test", &printf_hex_upper_test);
	load_test(&testlist, "Percent conversion test", &printf_percent_test);
	load_test(&testlist, "Integer width test", &printf_width_test);
	load_test(&testlist, "String precision test",
		&printf_string_precision_test);
	load_test(&testlist, "Integer precision test",
		&printf_integer_precision_test);
	load_test(&testlist, "Sign flag test", &printf_sign_test);
	load_test(&testlist, "Alternative form flag test",
		&printf_alternative_form_test);
	load_test(&testlist, "Zero padding flag test", &printf_zero_padding_test);
	load_test(&testlist, "Left alignment flag test",
		&printf_left_alignment_test);
	return (launch_tests(&testlist, "PRINTF"));
}
