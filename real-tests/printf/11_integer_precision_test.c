/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_integer_precision_test.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:22:23 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:22:23 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_printf.h"

int	printf_integer_precision_test(void)
{
	if (printf("[%.8d]\n", 42) == ft_printf("[%.8d]\n", 42))
		return (0);
	return (-1);
}
