/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:03:29 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/21 16:27:38 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_print	*initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = -1;
	tab->zero = 0;
	tab->dash = 0;
	tab->star = 0;
	tab->tl = 0;
	return (tab);
}

t_print	*reset_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = -1;
	tab->zero = 0;
	tab->dash = 0;
	tab->star = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		pos;
	int		ret;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	initialise_tab(tab);
	va_start(tab->args, format);
	pos = 0;
	ret = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
			pos = eval_format(tab, format, pos + 1);
		else
			ret += write(1, &format[pos], 1);
		pos++;
	}
	va_end(tab->args);
	ret += tab->tl;
	free(tab);
	return (ret);
}
