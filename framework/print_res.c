/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 05:56:33 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:19:41 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #ifndef BONUS : en compilation -D BONUS, ce fichier produit un objet
** VIDE, remplacé par print_res_bonus.c. */
#ifndef BONUS

# include "libunit.h"
# include "libft.h"		// ft_printf
# include <signal.h>	// SIGSEGV, SIGBUS

/* Affiche le verdict d'un test terminé proprement (exit).
** -!!status : !! normalise en 0 ou 1, le - donne donc 0 ou -1,
** ce qui correspond à la convention de retour attendue par launch_tests. */
int	print_res(int status)
{
	if (status == 0)
		ft_printf("[OK]\n");
	else
		ft_printf("[KO]\n");
	return (-!!status);
}

/* Affiche le verdict d'un test tué par un signal (WTERMSIG).
** Mandatory : seuls SIGSEGV et SIGBUS sont exigés par le sujet. */
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
