/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 05:55:01 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 06:16:34 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include "libft.h"		// ft_printf

#include <signal.h>		// SIGSEGV, SIGBUS

// TODO Handle colors in output
int	handle_res_print(int status)
{
	if (status == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (-!!status);
}

// TODO Handle colors in output
void	print_sig(int sig)
{
	if (sig == SIGSEGV)
		ft_printf("SIGSEGV\n");
	else if (sig == SIGBUS)
		ft_printf("SIGBUS\n");
}
