/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:01:03 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/18 18:44:29 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	align_hex_int_right(t_print *tab, unsigned long n)
{
	int	i;
	int	w;
	int	len;

	len = ft_numlen_base(n, 16);
	if (n == 0 && tab->prc == 0)
		len = 0;
	i = tab->prc - len;
	if (i < 0)
		w = tab->wdt - len;
	else
		w = tab->wdt - tab->prc;
	if (w < 0)
		w = 0;
	while (w-- > 0)
	{	
		if (tab->zero)
			tab->tl += write(1, "0", 1);
		else
			tab->tl += write(1, " ", 1);
	}
}

void	align_hex_int_left(t_print *tab, unsigned long n)
{
	int	i;
	int	w;
	int	len;

	len = ft_numlen_base(n, 16);
	if (n == 0 && tab->prc == 0)
		len = 0;
	i = tab->prc - len;
	if (i < 0)
		w = tab->wdt - len;
	else
		w = tab->wdt - tab->prc;
	if (w < 0)
		w = 0;
	while (w-- > 0)
		tab->tl += write(1, " ", 1);
}

void	align_uint_right(t_print *tab, unsigned int n)
{
	int	i;
	int	w;
	int	len;

	len = ft_numlen(n);
	if (n == 0 && tab->prc == 0)
		len = 0;
	i = tab->prc - len;
	if (i < 0)
		w = tab->wdt - len;
	else
		w = tab->wdt - tab->prc;
	if (w < 0)
		w = 0;
	while (w-- > 0)
	{	
		if (tab->zero)
			tab->tl += write(1, "0", 1);
		else
			tab->tl += write(1, " ", 1);
	}
}

void	align_uint_left(t_print *tab, unsigned int n)
{
	int	i;
	int	w;
	int	len;

	len = ft_numlen(n);
	if (n == 0 && tab->prc == 0)
		len = 0;
	i = tab->prc - len;
	if (i < 0)
		w = tab->wdt - len;
	else
		w = tab->wdt - tab->prc;
	if (w < 0)
		w = 0;
	while (w-- > 0)
		tab->tl += write(1, " ", 1);
}
