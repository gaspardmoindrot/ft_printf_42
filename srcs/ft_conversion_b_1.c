/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_b_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:10:14 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:13:17 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_printb_2(unsigned long h, t_printf p_l, int len, int i)
{
	p_l.ret = p_l.ret + len;
	if ((p_l.ash > 0 && h != 0)
			|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
		i++;
	while ((len + i) < p_l.nb_t)
	{
		ft_putchar('0');
		p_l.ret++;
		len++;
	}
	if ((p_l.ash > 0 && h != 0)
			|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
	{
		ft_putchar('0');
		p_l.ret++;
	}
	ft_putstr(ft_itoa_base_long(h, 2));
	return (p_l);
}

t_printf	ft_printb_3(unsigned long h, t_printf p_l, int len, int i)
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
	if ((p_l.ash > 0 && h != 0)
			|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
	{
		ft_putchar('0');
		p_l.ret++;
	}
	ft_putstr(ft_itoa_base_long(h, 2));
	return (p_l);
}

t_printf	ft_printb_4(unsigned long h, t_printf p_l, int len, int i)
{
	while ((i + len) < p_l.nb_t)
	{
		ft_putchar(' ');
		i++;
		p_l.ret++;
	}
	if ((p_l.ash > 0 && h != 0)
			|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
	{
		ft_putchar('0');
		p_l.ret++;
	}
	if (p_l.prec != 0 || h != 0)
		ft_putstr(ft_itoa_base_long(h, 2));
	return (p_l);
}

t_printf	ft_printb(unsigned long h, t_printf p_l)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(ft_itoa_base_long(h, 2));
	if (p_l.prec == 0 && h == 0 && p_l.nb_t > 0)
		p_l.nb_t++;
	if (p_l.sign_neg > 0)
		p_l = ft_printb_1(h, p_l, len, i);
	else if (p_l.zero > 0 && p_l.prec < 0)
		p_l = ft_printb_2(h, p_l, len, i);
	else
	{
		if ((p_l.ash > 0 && h != 0)
				|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
			i++;
		if (p_l.prec != 0 || h != 0)
			p_l.ret = p_l.ret + len;
		if (p_l.prec > len)
			p_l = ft_printb_3(h, p_l, len, i);
		else
			p_l = ft_printb_4(h, p_l, len, i);
	}
	return (p_l);
}
