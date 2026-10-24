/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bigger_str_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 22:03:44 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 11:35:36 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_strlen.h"

int	bigger_str_test(void)
{
	char	str[1000];

	str[999] = '\0';
	memset(str, 'a', 999);
	if (strlen(str) != ft_strlen(str))
		return (-1);
	return (0);
}
