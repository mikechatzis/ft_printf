/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printformat3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:49:57 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/22 15:24:06 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>

void	intprecu(t_print *tab, unsigned int i)
{
	int	k;

	k = tab->prc - ft_numlen(i);
	while (k-- > 0)
		tab->tl += write(1, "0", 1);
}

void	printpercent(t_print *tab)
{
	char	a;

	a = '%';
	if (tab->wdt && !tab->dash)
		align_int_right(tab, 1);
	tab->tl += write(1, &a, 1);
	if (tab->wdt && tab->dash)
		align_int_left(tab, 1);
}
