/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_embedded_null_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:26:48 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:26:48 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_strlen.h"

int	embedded_null_test(void)
{
	const char	str[] = {'a', 'b', '\0', 'c', 'd', '\0'};

	if (strlen(str) != ft_strlen(str))
		return (-1);
	return (0);
}
