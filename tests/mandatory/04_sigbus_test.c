/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sigbus_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:55:03 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 21:36:50 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_mandatory.h"

/* Même principe que sigsegv_test : le processus s'envoie SIGBUS. */
int	sigbus_test(void)
{
	raise(SIGBUS);
	return (-1);
}
