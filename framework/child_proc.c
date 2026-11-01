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

/* #ifndef BONUS : en compilation -D BONUS, ce fichier produit un objet
** VIDE, remplacé par child_proc_bonus.c — jamais deux définitions. */
#ifndef BONUS

# include "libunit.h"

/* Version mandatory de l'enfant : exécute simplement le test.
** Sa valeur de retour devient le code passé à exit() par exec_func. */
int	child_proc(t_unit_test *ut, const char *func_name)
{
	(void)func_name;
	return (ut->func());
}

#endif
