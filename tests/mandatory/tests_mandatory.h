/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_mandatory.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:47:42 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 21:25:32 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MANDATORY_H
# define TESTS_MANDATORY_H

# include "signal.h"	// raise, SIGSEGV, SIGBUS

int	mandatory_launcher(void);

int	ok_test(void);
int	ko_test(void);
int	sigsegv_test(void);
int	sigbus_test(void);

#endif // TESTS_MANDATORY_H
