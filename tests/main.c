/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:46:37 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 21:29:40 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/tests_mandatory.h"

#ifndef BONUS

int	main(void)
{
	mandatory_launcher();
}

#else

# include "bonus/tests_bonus.h"

int	main(void)
{
	mandatory_launcher();
	bonus_launcher();
}

#endif
