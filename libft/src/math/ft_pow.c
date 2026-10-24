/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:45:11 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 14:45:52 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(const double base, int exp)
{
	double	res;

	res = 1;
	if (exp > 0)
	{
		while (exp--)
			res *= base;
	}
	else if (exp < 0)
	{
		while (exp++)
			res /= base;
	}
	return (res);
}
