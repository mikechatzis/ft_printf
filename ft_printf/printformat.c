/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:54:01 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/22 14:36:11 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>

void	output_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	if (tab->wdt && !tab->dash)
		align_c(tab);
	tab->tl += write(1, &a, 1);
	if (tab->wdt && tab->dash)
		align_c(tab);
}

void	output_string(t_print *tab)
{
	char	*s;
	int		len;
	int		i;
	int		ipr;

	s = va_arg(tab->args, char *);
	if (!s)
	{	
		s = "(null)";
		if (tab->star)
			len = 0;
	}
	len = ft_strlen(s);
	ipr = tab->prc;
	i = -1;
	if (tab->wdt && !tab->dash)
		align_s(tab, len);
	if (tab->prc < 0)
		while (s[++i])
			tab->tl += write(1, &s[i], 1);
	else if (tab->prc > 0)
		while (s[++i] && ipr-- > 0)
			tab->tl += write(1, &s[i], 1);
	if (tab->wdt && tab->dash)
		align_s(tab, len);
}

void	intprec(t_print *tab, int i)
{
	int	k;

	k = tab->prc - ft_numlen(ft_abs(i));
	if (!tab->zero && i < 0)
		tab->tl += write(1, "-", 1);
	while (k-- > 0)
		tab->tl += write(1, "0", 1);
}

void	output_int(t_print *tab)
{
	int		i;
	int		k;
	char	*num;

	i = va_arg(tab->args, int);
	if (tab->zero && i < 0)
		tab->tl += write(1, "-", 1);
	if (tab->wdt && !tab->dash)
		align_int_right(tab, i);
	intprec(tab, i);
	num = ft_itoa(i);
	k = -1;
	if (i < 0)
		k++;
	while (num[++k])
	{	
		if (tab->prc == 0 && i == 0)
			break ;
		tab->tl += write(1, &num[k], 1);
	}
	if (tab->wdt && tab->dash)
		align_int_left(tab, i);
	free(num);
}

void	output_hexa_int(t_print *tab, int c)
{
	unsigned int	i;
	int				len;
	char			*num;

	i = va_arg(tab->args, unsigned int);
	len = ft_numlen_base(i, 16);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return ;
	num = ft_itoa_base(num, i, 16, c);
	if (tab->wdt && !tab->dash)
		align_hex_int_right(tab, i);
	if (tab->prc > len)
		printprchex(tab, i);
	while (num && len-- > 0)
	{	
		if (tab->prc == 0 && i == 0)
			break ;
		tab->tl += write(1, &num[len], 1);
	}
	if (tab->wdt && tab->dash)
		align_hex_int_left(tab, i);
	free(num);
}
