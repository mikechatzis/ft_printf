/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:32:54 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/21 16:26:38 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	eval_precision(t_print *tab, const char *format, int pos)
{
	pos++;
	tab->prc = 0;
	if (format[pos] == '*')
	{
		tab->star = 1;
		tab->prc = va_arg(tab->args, int);
		pos++;
		if (findchr(format[pos], "diuxX") && tab->prc >= 0)
			tab->zero = 0;
		return (pos);
	}
	else if (ft_isdigit(format[pos]))
	{
		while (format[pos] == '0')
			pos++;
		tab->prc = ft_atoi(&format[pos]);
		if (tab->prc == 0)
			return (pos);
		pos += ft_numlen(tab->prc);
	}
	if (findchr(format[pos], "diuxX") && tab->prc >= 0)
		tab->zero = 0;
	return (pos);
}

int	eval_dashnzero(t_print *tab, const char *format, int pos)
{
	if (format[pos] == '0')
	{
		tab->zero = 1;
		pos++;
	}
	while (format[pos] == '-' || format[pos] == '0')
	{
		if (format[pos] == '-')
		{	
			tab->zero = 0;
			tab->dash = 1;
		}
		pos++;
	}
	return (pos);
}

int	eval_width(t_print *tab, const char *format, int pos)
{
	pos = eval_dashnzero(tab, format, pos);
	if (format[pos] == '*')
	{
		tab->wdt = va_arg(tab->args, int);
		if (tab->wdt < 0)
		{
			tab->dash = 1;
			tab->zero = 0;
			tab->wdt *= -1;
		}
		pos++;
	}
	if (findchr(format[pos], "123456789"))
	{
		tab->wdt = ft_atoi(&format[pos]);
		pos += ft_numlen(tab->wdt);
	}
	if (format[pos] == '.')
		pos = eval_precision(tab, format, pos);
	return (pos);
}
