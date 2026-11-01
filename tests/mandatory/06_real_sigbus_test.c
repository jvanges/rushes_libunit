/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_real_sigbus_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:53:13 by mmichele          #+#    #+#             */
/*   Updated: 2026/10/25 16:53:13 by mmichele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_mandatory.h"
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

/* Provoque un VRAI SIGBUS (contrairement à raise) :
** - on crée un fichier d'1 SEUL octet (ftruncate)
** - on le projette en mémoire sur 8192 octets (mmap réussit :
**   le mapping est valide, arrondi à des pages entières)
** - lire mapping[4096] touche une page du mapping SANS données
**   derrière dans le fichier -> SIGBUS.
** Différence avec SIGSEGV : celui-ci survient quand l'adresse est
** HORS de tout mapping valide (ex. pointeur NULL). */
int	real_sigbus_test(void)
{
	FILE			*file;
	volatile char	*mapping;
	volatile char	value;

	file = tmpfile();
	if (!file)
		return (-1);
	if (ftruncate(fileno(file), 1) == -1)
	{
		fclose(file);
		return (-1);
	}
	mapping = mmap(0, 8192, PROT_READ, MAP_SHARED, fileno(file), 0);
	if (mapping == MAP_FAILED)
	{
		fclose(file);
		return (-1);
	}
	value = mapping[4096];
	(void)value;
	munmap((void *)mapping, 8192);
	fclose(file);
	return (-1);
}
