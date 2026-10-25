/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_real_sigpipe_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:53:48 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 16:53:49 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_bonus.h"
#include <unistd.h>

int	real_sigpipe_test(void)
{
	int	pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		return (-1);
	close(pipe_fds[0]);
	write(pipe_fds[1], "x", 1);
	close(pipe_fds[1]);
	return (-1);
}
