/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_multiple_strings_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:26:52 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:26:53 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_strlen.h"

int	multiple_strings_test(void)
{
	const char	*values[] = {"a", "libft", "0123456789", "last value"};
	size_t		i;

	i = 0;
	while (i < sizeof(values) / sizeof(values[0]))
	{
		if (strlen(values[i]) != ft_strlen(values[i]))
			return (-1);
		i++;
	}
	return (0);
}
