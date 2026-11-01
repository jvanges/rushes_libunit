/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_sigsegv_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:55:03 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 21:36:53 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_mandatory.h"

/* raise(SIGSEGV) : le processus s'envoie le signal à lui-même.
** Mort "par signal" garantie : le parent prend le chemin WIFSIGNALED,
** exactement comme pour un vrai crash. */
int	sigsegv_test(void)
{
	raise(SIGSEGV);
	return (-1);
}
