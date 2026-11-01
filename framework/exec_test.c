/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 04:20:00 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:18:46 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <unistd.h>		// fork
#include <sys/types.h>	// pid_t
#include <stdlib.h>		// exit
#include <sys/wait.h>	// wait
#include <signal.h>		// SIGALRM

#include "libft.h"		// ft_dprintf

/* Exécute UN test dans un processus enfant, puis analyse sa mort.
**
** fork() :
**   -1  -> échec, on abandonne ce test
**    0  -> branche ENFANT : exécute le test, son retour devient le exit code
**   >0  -> branche PARENT : wait() bloque jusqu'à la mort de l'enfant
**
** Analyse de status (rempli par wait) :
**   WIFEXITED   -> l'enfant a fait exit() : WEXITSTATUS donne le code
**                  (0 -> [OK], autre -> [KO])
**   WIFSIGNALED -> l'enfant a été tué par un signal : WTERMSIG donne lequel
**                  (SIGSEGV -> [SIGSEGV], SIGBUS -> [SIGBUS])
**
** Retour : 0 si le test a réussi, -1 dans tous les autres cas. */
int	exec_func(t_unit_test *ut, const char *func_name)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		ft_dprintf(2, "fork failed\n");
		return (-1);
	}
	else if (pid == 0)
		exit(child_proc(ut, func_name));
	else
	{
		if (wait(&status) == -1)
		{
			ft_dprintf(2, "wait failed\n");
			return (-1);
		}
	}
	if (WIFEXITED(status))
		return (print_res(WEXITSTATUS(status)));
	else if (WIFSIGNALED(status))
		print_sig(WTERMSIG(status));
	return (-1);
}
