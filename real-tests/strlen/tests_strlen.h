/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_strlen.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 22:00:25 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/24 11:35:23 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_STRLEN_H
# define TESTS_STRLEN_H

# include <string.h>	// strlen
# include "libft.h"		// ft_strlen

int	strlen_launcher(void);

int	basic_test(void);
int	null_test(void);
int	bigger_str_test(void);
int	empty_test(void);
int	embedded_null_test(void);
int	special_characters_test(void);
int	multiple_strings_test(void);

#endif // TESTS_STRLEN_H
