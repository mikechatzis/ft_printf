/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:49:04 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/21 15:55:00 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	align_s(t_print *tab, int len)
{
	int	w;

	w = tab->wdt - len;
	if (w < 0 && tab->prc > len)
		return ;
	if (tab->prc < len)
	{
		if (tab->prc >= 0)
			w += len - tab->prc;
		while (w-- > 0)
			tab->tl += write(1, " ", 1);
	}
	else
		while (w-- > 0)
			tab->tl += write(1, " ", 1);
}

void	align_c(t_print *tab)
{
	int	w;

	w = tab->wdt;
	while (--w > 0)
		tab->tl += write(1, " ", 1);
}

void	align_int_right(t_print *tab, int n)
{
	int	i;
	int	w;

	i = tab->prc - ft_numlen(ft_abs(n));
	if (i < 0)
		w = tab->wdt - ft_numlen(ft_abs(n));
	else
		w = tab->wdt - tab->prc;
	if (w < 0)
		w = 0;
	if (n < 0)
		w--;
	if (!n && !tab->prc)
		w++;
	while (w-- > 0)
	{	
		if (tab->zero)
			tab->tl += write(1, "0", 1);
		else
			tab->tl += write(1, " ", 1);
	}
}

void	align_int_left(t_print *tab, int n)
{
	int	i;
	int	w;

	i = tab->prc - ft_numlen(ft_abs(n));
	if (i < 0)
		w = tab->wdt - ft_numlen(ft_abs(n));
	else
		w = tab->wdt - tab->prc;
	if (n < 0)
		w--;
	if (w < 0)
		w = 0;
	if (!n && !tab->prc)
		w++;
	while (w-- > 0)
		tab->tl += write(1, " ", 1);
}
