/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 04:20:00 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:49:44 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS

# include "libunit.h"
# include <fcntl.h>		// open
# include <unistd.h>	// fork
# include <sys/types.h>	// pid_t
# include <stdlib.h>	// exit
# include <sys/wait.h>	// wait
# include <signal.h>	// SIGALRM
# include <sys/time.h>	// gettimeofday
# include <time.h>		// localtime
# include "libft.h"		// ft_dprintf

static void	print_timestamp(int fd, const char *label, struct timeval stamp)
{
	struct tm	*date;

	date = localtime(&stamp.tv_sec);
	if (!date)
		return ;
	ft_dprintf(fd, "%s: %d-%d-%d %d:%d:%d.%d\n", label,
		date->tm_year + 1900, date->tm_mon + 1, date->tm_mday,
		date->tm_hour, date->tm_min, date->tm_sec, (int)stamp.tv_usec);
}

static void	file_logger(t_unit_test *ut, const char *func_name,
	struct timeval start, struct timeval stop)
{
	char	*log_name;
	int		fd;
	int		execution_time;

	log_name = ft_strjoin(func_name, ".log");
	if (!log_name)
		return ;
	fd = open(log_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	free(log_name);
	if (fd == -1)
		return ;
	execution_time = (int)((stop.tv_sec - start.tv_sec) * 1000000L
			+ stop.tv_usec - start.tv_usec);
	ft_dprintf(fd, "Test: %s\n", ut->title);
	print_timestamp(fd, "Started", start);
	print_timestamp(fd, "Stopped", stop);
	ft_dprintf(fd, "Duration: %d.%d seconds\n\n", execution_time / 1000000,
		execution_time % 1000000);
	close(fd);
}

static int	wait_for_child(int *status)
{
	if (wait(status) == -1)
	{
		ft_dprintf(2, "wait failed\n");
		return (-1);
	}
	return (0);
}

int	exec_func(t_unit_test *ut, const char *func_name)
{
	pid_t			pid;
	int				status;
	struct timeval	start;
	struct timeval	stop;

	gettimeofday(&start, NULL);
	pid = fork();
	if (pid == -1)
	{
		ft_dprintf(2, "fork failed\n");
		return (-1);
	}
	else if (pid == 0)
		exit(child_proc(ut, func_name));
	else if (wait_for_child(&status) == -1)
		return (-1);
	gettimeofday(&stop, NULL);
	file_logger(ut, func_name, start, stop);
	if (WIFEXITED(status))
		return (print_res(WEXITSTATUS(status)));
	else if (WIFSIGNALED(status))
		print_sig(WTERMSIG(status));
	return (-1);
}

#endif
