/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 05:56:33 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 13:59:11 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS

# include "libunit.h"
# include "libft.h"		// ft_printf
# include <signal.h>	// SIGSEGV, SIGBUS

int	print_res(int status)
{
	if (status == 0)
		ft_printf("[OK]\n");
	else
		ft_printf("[KO]\n");
	return (-!!status);
}

void	print_sig(int sig)
{
	if (sig == SIGSEGV)
		ft_printf("[SIGSEGV]\n");
	else if (sig == SIGBUS)
		ft_printf("[SIGBUS]\n");
	else
		ft_printf("ERROR");
}

#endif
