/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 02:06:41 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 20:19:02 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS

# include "libunit.h"

int	child_proc(t_unit_test *ut, const char *func_name)
{
	(void)func_name;
	return (ut->func());
}

#endif
