/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_real_sigsegv_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:53:10 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 16:53:10 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_mandatory.h"

/* Provoque un VRAI SIGSEGV en déréférençant un pointeur NULL.
** "volatile" empêche le compilateur d'optimiser/supprimer l'accès. */
int	real_sigsegv_test(void)
{
	volatile int	*ptr;

	ptr = 0;
	return (*ptr);
}
