/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:34:00 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 14:48:50 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_atoi.h"

int	atoi_basic_test(void)
{
	const char	*values[] = {"0", "42", "-42", "+42", "123456789"};
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
