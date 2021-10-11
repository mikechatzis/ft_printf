/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:55:14 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/22 15:26:46 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	eval_variable(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		output_char(tab);
	else if (format[pos] == 's')
		output_string(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		output_int(tab);
	else if (format[pos] == 'u')
		output_unsigned_int(tab);
	else if (format[pos] == 'p')
		output_pointer(tab);
	else if (format[pos] == 'x' || format[pos] == 'X')
		output_hexa_int(tab, format[pos] - 23);
	return (pos);
}

int	eval_format(t_print *tab, const char *format, int pos)
{
	while (!(ft_isalpha(format[pos])))
	{
		if (format[pos] == '.')
			pos = eval_precision(tab, format, pos);
		if (ft_isdigit(format[pos]) || format[pos] == '-' || format[pos] == '*')
			pos = eval_width(tab, format, pos);
		if (format[pos] == '%')
		{	
			printpercent(tab);
			reset_tab(tab);
			return (pos);
		}
	}
	pos = eval_variable(tab, format, pos);
	reset_tab(tab);
	return (pos);
}
