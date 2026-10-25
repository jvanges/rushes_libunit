/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 02:09:35 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 21:00:15 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/tests_mandatory.h"
#include "bonus/tests_bonus.h"

int	main(void)
{
	int	status;

	status = 0;
	status |= (mandatory_launcher() != 0);
	status |= (bonus_launcher() != 0);
	if (status)
		return (-1);
	return (0);
}
