/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_sign_position_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:26:41 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:26:41 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_atoi.h"

int	atoi_sign_position_test(void)
{
	const char	*values[] = {"--1", "++1", "+-1", "-+1", " - 1"};
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
