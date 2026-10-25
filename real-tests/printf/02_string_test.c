/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_string_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 13:00:49 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:18:34 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_printf.h"

int	printf_string_test(void)
{
	const char	*value = "Hello, printf !";

	if (printf("%s\n", value) == ft_printf("%s\n", value))
		return (0);
	return (-1);
}
