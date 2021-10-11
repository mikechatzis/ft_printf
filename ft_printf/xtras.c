/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtras.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:39:10 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/19 10:00:53 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

int	ft_numlen(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	findchr(const char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (n *= -1);
}

int	ft_numlen_base(unsigned long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i += 1;
		return (i);
	}
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

char	*ft_itoa_base(char *str, unsigned long n, int base, int c)
{
	int	i;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	while (n > 0)
	{
		if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + c;
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (str);
}
