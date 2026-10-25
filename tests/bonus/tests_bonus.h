/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:47:42 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 14:50:25 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_BONUS_H
# define TESTS_BONUS_H

# include "signal.h"	// raise, SIGSEGV, SIGBUS

int	bonus_launcher(void);

int	sigabrt_test(void);
int	sigfpe_test(void);
int	sigpipe_test(void);
int	sigill_test(void);
int	timeout_test(void);

#endif // TESTS_BONUS_H
