/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_x_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:32:40 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:35:29 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_printx_1(unsigned long h, t_printf p_l, int len, int i)
{
	if (p_l.ash > 0 && h != 0)
	{
		ft_putstr("0x");
		p_l.ret = p_l.ret + 2;
		i = i + 2;
	}
	if (p_l.prec != 0 || h != 0)
		p_l.ret = p_l.ret + len;
	while (len < p_l.prec)
	{
		ft_putchar('0');
		p_l.ret++;
		len++;
	}
	if (p_l.prec != 0 || h != 0)
		ft_putstr(ft_itoa_base_long_x(h, 16));
	p_l = ft_cl_print_d_3_1(p_l, i, len);
	return (p_l);
}

t_printf	ft_printx_2(unsigned long h, t_printf p_l, int len, int i)
{
	p_l.ret = p_l.ret + len;
	if (p_l.ash > 0 && h != 0)
	{
		ft_putstr("0x");
		i = i + 2;
		p_l.ret = p_l.ret + 2;
	}
	while ((len + i) < p_l.nb_t)
	{
		ft_putchar('0');
		p_l.ret++;
		len++;
	}
	ft_putstr(ft_itoa_base_long_x(h, 16));
	return (p_l);
}

t_printf	ft_printx_3(unsigned long h, t_printf p_l, int len, int i)
{
	if (p_l.ash > 0 && h != 0)
	{
		ft_putstr("0x");
		p_l.ret = p_l.ret + 2;
	}
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
	ft_putstr(ft_itoa_base_long_x(h, 16));
	return (p_l);
}

t_printf	ft_printx_4(unsigned long h, t_printf p_l, int len, int i)
{
	while ((i + len) < p_l.nb_t)
	{
		ft_putchar(' ');
		i++;
		p_l.ret++;
	}
	if (p_l.ash > 0 && h != 0)
	{
		ft_putstr("0x");
		p_l.ret = p_l.ret + 2;
	}
	if (p_l.prec != 0 || h != 0)
		ft_putstr(ft_itoa_base_long_x(h, 16));
	return (p_l);
}

t_printf	ft_printx(unsigned long h, t_printf p_l)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(ft_itoa_base_long_x(h, 16));
	if (p_l.prec == 0 && h == 0 && p_l.nb_t > 0)
		p_l.nb_t++;
	if (p_l.sign_neg > 0)
		p_l = ft_printx_1(h, p_l, len, i);
	else if (p_l.zero > 0 && p_l.prec < 0)
		p_l = ft_printx_2(h, p_l, len, i);
	else
	{
		if (p_l.ash > 0 && h != 0)
			i = i + 2;
		if (p_l.prec != 0 || h != 0)
			p_l.ret = p_l.ret + len;
		if (p_l.prec > len)
			p_l = ft_printx_3(h, p_l, len, i);
		else
			p_l = ft_printx_4(h, p_l, len, i);
	}
	return (p_l);
}
