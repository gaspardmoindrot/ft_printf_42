/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:31:13 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:32:07 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		ft_putnbr_u_long(unsigned long n)
{
	if (n > 9)
	{
		ft_putnbr_u_long(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

t_printf	ft_printu_1(unsigned long h, t_printf p_l, int len, int i)
{
	if (p_l.prec != 0 || h != 0)
		p_l.ret = p_l.ret + len;
	while (len < p_l.prec)
	{
		ft_putchar('0');
		p_l.ret++;
		len++;
	}
	if (p_l.prec != 0 || h != 0)
		ft_putnbr_u_long(h);
	p_l = ft_cl_print_d_3_1(p_l, i, len);
	return (p_l);
}

t_printf	ft_printu_2_1(unsigned long h, t_printf p_l, int len, int i)
{
	while ((i + p_l.prec) < p_l.nb_t)
	{
		ft_putchar(' ');
		i++;
		p_l.ret++;
	}
	while (len < p_l.prec)
	{
		ft_putchar('0');
		p_l.ret++;
		len++;
	}
	ft_putnbr_u_long(h);
	return (p_l);
}

t_printf	ft_printu_2(unsigned long h, t_printf p_l, int len, int i)
{
	if (p_l.prec != 0 || h != 0)
		p_l.ret = p_l.ret + len;
	if (p_l.prec > len)
		p_l = ft_printu_2_1(h, p_l, len, i);
	else
	{
		while ((i + len) < p_l.nb_t)
		{
			ft_putchar(' ');
			i++;
			p_l.ret++;
		}
		if (p_l.prec != 0 || h != 0)
			ft_putnbr_u_long(h);
	}
	return (p_l);
}

t_printf	ft_printu(unsigned long h, t_printf p_l)
{
	int	len;
	int	i;

	i = 0;
	len = len_nb_u_long(h);
	if (p_l.prec == 0 && h == 0 && p_l.nb_t > 0)
		p_l.nb_t++;
	if (p_l.sign_neg > 0)
		p_l = ft_printu_1(h, p_l, len, i);
	else if (p_l.zero > 0 && p_l.prec < 0)
	{
		p_l.ret = p_l.ret + len;
		while ((len + i) < p_l.nb_t)
		{
			ft_putchar('0');
			p_l.ret++;
			len++;
		}
		ft_putnbr_u_long(h);
	}
	else
		p_l = ft_printu_2(h, p_l, len, i);
	return (p_l);
}
