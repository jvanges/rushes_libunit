/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:46:37 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 21:00:24 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen/tests_strlen.h"
#include "atoi/tests_atoi.h"
#include "printf/tests_printf.h"

int	main(void)
{
	int	status;

	status = 0;
	status |= (strlen_launcher() != 0);
	status |= (atoi_launcher() != 0);
	status |= (printf_launcher() != 0);
	if (status)
		return (-1);
	return (0);
}
