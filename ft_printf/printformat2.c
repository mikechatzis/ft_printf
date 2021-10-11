/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printformat2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:36:54 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/22 15:41:17 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>

void	output_unsigned_int(t_print *tab)
{
	unsigned int	i;
	int				k;
	char			*num;

	i = va_arg(tab->args, int);
	num = ft_uitoa(i);
	k = 0;
	if (!num)
		return ;
	if (tab->wdt && !tab->dash)
		align_uint_right(tab, i);
	intprecu(tab, i);
	while (num[k])
	{
		if (tab->prc == 0 && i == 0)
			break ;
		tab->tl += write(1, &num[k++], 1);
	}
	if (tab->wdt && tab->dash)
		align_uint_left(tab, i);
	free(num);
}

void	write_nullp(t_print *tab)
{
	int	w;
	int	p;

	w = tab->wdt - 3;
	p = tab->prc;
	if (tab->prc > 3)
		w = tab->wdt - tab->prc;
	if (tab->wdt > tab->prc && !tab->dash)
	{
		while (w-- > 0)
			tab->tl += write(1, " ", 1);
	}
	tab->tl += write(1, "0x0", 3);
	while (p-- > 3)
		tab->tl += write(1, "0", 1);
	if (tab->wdt > tab->prc && tab->dash)
	{
		while (w-- > 0)
			tab->tl += write(1, " ", 1);
	}
}

void	pntprec(t_print *tab, unsigned long i)
{
	int	k;

	k = tab->prc - ft_numlen_base(i, 16);
	if (!tab->zero)
		tab->tl += write(1, "0x", 2);
	while (k-- > 0)
		tab->tl += write(1, "0", 1);
}

void	output_pointer(t_print *tab)
{
	unsigned long	i;

	i = (unsigned long)va_arg(tab->args, void *);
	if (!i)
	{
		write_nullp(tab);
		return ;
	}
	if (tab->zero)
		tab->tl = write(1, "0x", 2);
	if (tab->wdt && !tab->dash)
		align_pnt_right(tab, i);
	pntprec(tab, i);
	if (i)
		tab->tl += ft_putnbr_base(i, "0123456789abcdef");
	if (tab->wdt && tab->dash)
		align_pnt_left(tab, i);
}

void	printprchex(t_print *tab, unsigned int i)
{
	int	len;
	int	w;

	len = ft_numlen_base(i, 16);
	w = tab->prc - len;
	if (w > 0)
		while (w-- > 0)
			tab->tl += write(1, "0", 1);
}
