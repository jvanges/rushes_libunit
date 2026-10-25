/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_string_precision_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:22:20 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:22:20 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_printf.h"

int	printf_string_precision_test(void)
{
	if (printf("[%.5s]\n", "abcdef") == ft_printf("[%.5s]\n", "abcdef"))
		return (0);
	return (-1);
}
