/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtras2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:42:36 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/18 18:44:10 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"
#include "libft/libft.h"

char	*ft_uitoa(unsigned int nb)
{
	char	*a;
	int		l;

	l = ft_numlen(nb);
	a = (char *)malloc(sizeof(char) * (l + 1));
	if (!a)
		return (NULL);
	a[l--] = '\0';
	if (nb == 0)
		a[l] = 0 + '0';
	while (nb > 0)
	{
		a[l--] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;
	unsigned long	num;
	int				len;

	len = 1;
	num = n;
	base_len = ft_strlen(base);
	if (num == 0)
	{
		ft_putchar('0');
		return (len);
	}
	if (num >= base_len)
	{
		len += ft_putnbr_base(num / base_len, base);
		ft_putchar(base[num % base_len]);
	}
	else if (num < base_len)
		ft_putchar(base[num]);
	return (len);
}
