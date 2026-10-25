/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_zero_padding_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:22:30 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:22:30 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_printf.h"

int	printf_zero_padding_test(void)
{
	if (printf("%08d\n", 42) == ft_printf("%08d\n", 42))
		return (0);
	return (-1);
}
