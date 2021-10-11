/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:27:32 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/22 15:20:51 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_print
{	
	va_list	args;
	int		wdt;
	int		prc;
	int		zero;
	int		dash;
	int		star;
	int		tl;
}t_print;

int		ft_putnbr_base(unsigned long n, char *base);
char	*ft_uitoa(unsigned int nb);
int		ft_putchar(char c);
int		ft_numlen(long n);
int		findchr(const char c, const char *str);
int		ft_abs(int n);
int		ft_numlen_base(unsigned long n, int base);
char	*ft_itoa_base(char *str, unsigned long n, int base, int c);
void	intprecu(t_print *tab, unsigned int i);
void	output_unsigned_int(t_print *tab);
void	write_nullp(t_print *tab);
void	pntprec(t_print *tab, unsigned long i);
void	output_pointer(t_print *tab);
void	printprchex(t_print *tab, unsigned int i);
void	output_char(t_print *tab);
void	output_string(t_print *tab);
void	intprec(t_print *tab, int i);
void	output_int(t_print *tab);
void	output_hexa_int(t_print *tab, int c);
void	align_pnt_right(t_print *tab, unsigned long n);
void	align_pnt_left(t_print *tab, unsigned long n);
int		eval_precision(t_print *tab, const char *format, int pos);
int		eval_dashnzero(t_print *tab, const char *format, int pos);
int		eval_width(t_print *tab, const char *format, int pos);
int		eval_variable(t_print *tab, const char *format, int pos);
int		eval_format(t_print *tab, const char *format, int pos);
void	align_hex_int_right(t_print *tab, unsigned long n);
void	align_hex_int_left(t_print *tab, unsigned long n);
void	align_uint_right(t_print *tab, unsigned int n);
void	align_uint_left(t_print *tab, unsigned int n);
void	align_s(t_print *tab, int len);
void	align_c(t_print *tab);
void	align_int_right(t_print *tab, int n);
void	align_int_left(t_print *tab, int n);
t_print	*initialise_tab(t_print *tab);
t_print	*reset_tab(t_print *tab);
void	printpercent(t_print *tab);
int		ft_printf(const char *format, ...);

#endif