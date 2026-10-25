/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 02:05:54 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 17:25:13 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS

# include "libunit.h"
# include <stdio.h>		// FILE tmpfile fclose fseek fflush fread
# include <stdlib.h>	// malloc free
# include <string.h>	// memcmp
# include <unistd.h>	// alarm

static int	output_is_identical(FILE *output)
{
	long			length;
	char			*content;
	unsigned int	half_length;
	int				result;

	if (fflush(stdout) != 0 || fseek(output, 0, SEEK_END) != 0)
		return (0);
	length = ftell(output);
	if (length < 0 || length % 2 != 0 || fseek(output, 0, SEEK_SET) != 0)
		return (0);
	content = malloc((unsigned int)length + 1);
	if (!content)
		return (0);
	if (fread(content, 1, (unsigned int)length, output) != (unsigned int)length)
	{
		free(content);
		return (0);
	}
	content[length] = '\0';
	half_length = (unsigned int)length / 2;
	result = memcmp(content, content + half_length, half_length) == 0;
	free(content);
	return (result);
}

int	child_proc(t_unit_test *ut)
{
	FILE	*output;
	int		status;
	int		same_output;

	alarm(5);
	output = tmpfile();
	if (!output)
		return (1);
	fflush(stdout);
	if (dup2(fileno(output), STDOUT_FILENO) == -1)
	{
		fclose(output);
		return (1);
	}
	status = ut->func();
	same_output = output_is_identical(output);
	fclose(output);
	if (status != 0 || !same_output)
		return (-1);
	return (0);
}

#endif
