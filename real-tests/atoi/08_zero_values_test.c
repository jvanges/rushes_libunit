/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_zero_values_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:26:43 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:26:43 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_atoi.h"

int	atoi_zero_values_test(void)
{
	const char	*values[] = {"0", "+0", "-0", "000000", "  -000"};
	size_t		i;

	i = 0;
	while (i < sizeof(values) / sizeof(values[0]))
	{
		if (atoi(values[i]) != ft_atoi(values[i]))
			return (-1);
		i++;
	}
	return (0);
}
