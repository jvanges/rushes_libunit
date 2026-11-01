/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 22:03:33 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 14:58:13 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_strlen.h"

/* strlen(NULL) est un comportement indéfini -> segfault.
** Ce test est donc CENSÉ crasher : il démontre que le framework
** rapporte [SIGSEGV] proprement au lieu de mourir lui-même. */
int	null_test(void)
{
	const char	*ptr = NULL;

	if (strlen(ptr) != strlen(ptr))
		return (-1);
	return (0);
}
