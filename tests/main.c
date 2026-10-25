/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:46:37 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 21:00:09 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/tests_mandatory.h"

int	main(void)
{
	int	status;

	status = 0;
	status |= (mandatory_launcher() != 0);
	if (status)
		return (-1);
	return (0);
}
