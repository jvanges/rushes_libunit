/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 04:20:00 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 12:40:55 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

#include <unistd.h>		// fork
#include <sys/types.h>	// pid_t
#include <stdlib.h>		// exit
#include <sys/wait.h>	// waitpid

#include "libft.h"		// ft_dprintf

int	exec_func(t_unit_test *ut)
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
		exit(child_proc(ut));
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			ft_dprintf(2, "waitpid failed\n");
	}
	if (WIFEXITED(status))
		return (print_res(WEXITSTATUS(status)));
	else if (WIFSIGNALED(status))
		print_sig(WTERMSIG(status));
	return (-1);
}
