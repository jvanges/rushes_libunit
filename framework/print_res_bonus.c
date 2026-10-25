/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 05:55:01 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:59:00 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS

# include "libunit.h"
# include "libft.h"		// ft_aec_print
# include <signal.h>

int	print_res(int status)
{
	if (status == 0)
		ft_aec_print((t_aec){NORMAL, GREEN, DEFAULT}, "[OK]", 1);
	else
		ft_aec_print((t_aec){NORMAL, RED, DEFAULT}, "[KO]", 1);
	return (-!!status);
}

void	print_sig(int sig)
{
	if (sig == SIGSEGV)
		ft_aec_print((t_aec){NORMAL, YELLOW, DEFAULT}, "[SIGSEGV]", 1);
	else if (sig == SIGBUS)
		ft_aec_print((t_aec){NORMAL, YELLOW, DEFAULT}, "[SIGBUS]", 1);
	else if (sig == SIGABRT)
		ft_aec_print((t_aec){NORMAL, YELLOW, DEFAULT}, "[SIGABRT]", 1);
	else if (sig == SIGFPE)
		ft_aec_print((t_aec){NORMAL, YELLOW, DEFAULT}, "[SIGFPE]", 1);
	else if (sig == SIGPIPE)
		ft_aec_print((t_aec){NORMAL, YELLOW, DEFAULT}, "[SIGPIPE]", 1);
	else if (sig == SIGILL)
		ft_aec_print((t_aec){NORMAL, YELLOW, DEFAULT}, "[SIGILL]", 1);
	else if (sig == SIGALRM)
		ft_aec_print((t_aec){NORMAL, MAGENTA, DEFAULT}, "[TIMEOUT]", 1);
	else
		ft_printf("ERROR");
}

#endif
