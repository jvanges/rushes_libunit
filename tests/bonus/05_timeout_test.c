/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_timeout_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:50:08 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 16:50:43 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"

/* Simule un timeout via raise(SIGALRM) : c'est le signal que le noyau
** enverrait réellement via alarm(5) si le test bouclait trop longtemps. */
int	timeout_test(void)
{
	raise(SIGALRM);
	return (-1);
}
