/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_pointer_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 13:00:41 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:18:50 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_printf.h"

int	printf_pointer_test(void)
{
	const int	value = 42;

	if (printf("%p\n", &value) == ft_printf("%p\n", &value))
		return (0);
	return (-1);
}
