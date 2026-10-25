/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_real_sigfpe_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:53:46 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 16:59:11 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"

int	real_sigfpe_test(void)
{
	int				dividend;
	volatile int	divisor;

	dividend = 1;
	divisor = 0;
	__asm__ volatile (
		"cltd\n\t"
		"idivl %1"
		: "+a"(dividend)
		: "rm"(divisor)
		: "edx"
	);
	return (dividend);
}
