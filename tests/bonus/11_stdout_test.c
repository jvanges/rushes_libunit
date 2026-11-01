/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_stdout_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:55:03 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 21:21:57 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"

#include "unistd.h"

/* Valide la vérification de stdout du bonus (invalidée volontairement).
** En bonus, l'enfant redirige stdout vers un tmpfile et compare les
** deux MOITIÉS de la sortie capturée. Ici on écrit "abc\0" puis "def\0"
** (4 octets chacun) : les moitiés diffèrent -> KO attendu ("INVALID STDOUT").
** Note : le test renvoie 0, c'est bien la comparaison de sortie qui le
** fait échouer. */
int	stdout_test(void)
{
	write(1, "abc", 4);
	write(1, "def", 4);
	return (0);
}
