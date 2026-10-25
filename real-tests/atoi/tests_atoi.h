/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_atoi.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:34:00 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 14:53:58 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_ATOI_H
# define TESTS_ATOI_H

# include <stdlib.h>	// atoi
# include "libft.h"		// ft_atoi

int	atoi_launcher(void);

int	atoi_basic_test(void);
int	atoi_whitespace_test(void);
int	atoi_invalid_characters_test(void);
int	atoi_limits_test(void);
int	atoi_null_test(void);
int	atoi_trailing_whitespace_test(void);
int	atoi_sign_position_test(void);
int	atoi_zero_values_test(void);

#endif
