/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 13:00:51 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 13:01:05 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_printf.h"

/* Compare printf (libc) et ft_printf (libft) sur DEUX aspects :
** 1. la valeur de retour (nombre de caractères imprimés)
** 2. le contenu affiché : en bonus, l'enfant capture stdout et compare
**    les deux moitiés de la sortie ([printf][ft_printf]).
** Convention : 0 = succès, -1 = échec. */
int	printf_basic_test(void)
{
	if (printf("%c\n", 'A') == ft_printf("%c\n", 'A'))
		return (0);
	return (-1);
}
