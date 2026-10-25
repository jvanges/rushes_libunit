/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_special_characters_test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:26:50 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:26:50 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_strlen.h"

int	special_characters_test(void)
{
	const char	*str = "\t\n\v\f\r !@#$%^&*()";

	if (strlen(str) != ft_strlen(str))
		return (-1);
	return (0);
}
