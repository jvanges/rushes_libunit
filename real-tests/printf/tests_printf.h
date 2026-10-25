/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 13:01:19 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:24:46 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_PRINTF_H
# define TESTS_PRINTF_H

# include <stdio.h>
# include "libft.h"

int	printf_launcher(void);

int	printf_basic_test(void);
int	printf_string_test(void);
int	printf_integer_test(void);
int	printf_unsigned_test(void);
int	printf_pointer_test(void);
int	printf_hex_lower_test(void);
int	printf_hex_upper_test(void);
int	printf_percent_test(void);
int	printf_width_test(void);
int	printf_string_precision_test(void);
int	printf_integer_precision_test(void);
int	printf_sign_test(void);
int	printf_alternative_form_test(void);
int	printf_zero_padding_test(void);
int	printf_left_alignment_test(void);

#endif // TESTS_PRINTF_H
