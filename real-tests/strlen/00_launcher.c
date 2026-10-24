/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:30:42 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 06:23:08 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_strlen.h"

#include "libunit.h"

#include "libft.h"

#include <unistd.h>

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = 0;
	ft_printf("STRLEN: \n");
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "NULL test", &null_test);
	load_test(&testlist, "Bigger string test", &bigger_str_test);
	return (launch_tests(&testlist));
}
