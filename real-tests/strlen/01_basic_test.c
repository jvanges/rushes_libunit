/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:33:14 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 05:22:59 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>	// strlen
#include "libft.h"	// ft_strlen

int	basic_test(void)
{
	const char	*str = "Hello World !";

	if (strlen(str) != ft_strlen(str))
		return (-1);
	return (0);
}
