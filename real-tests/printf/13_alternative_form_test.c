/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_alternative_form_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:22:27 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:26:20 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_printf.h"

int	printf_alternative_form_test(void)
{
	if (printf("%#x\n", 424242) == ft_printf("%#x\n", 424242))
		return (0);
	return (-1);
}
