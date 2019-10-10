/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_o_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:13:35 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:16:40 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_printo_2(unsigned long h, t_printf p_l, int len, int i)
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
	if ((p_l.ash > 0 && h != 0 && p_l.prec < len)
			|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
	{
		ft_putchar('0');
		p_l.ret++;
	}
	ft_putstr(ft_itoa_base_long(h, 8));
	return (p_l);
}

t_printf	ft_printo_3(unsigned long h, t_printf p_l, int len, int i)
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
	if ((p_l.ash > 0 && h != 0 && p_l.prec < len)
			|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
	{
		ft_putchar('0');
		p_l.ret++;
	}
	ft_putstr(ft_itoa_base_long(h, 8));
	return (p_l);
}

t_printf	ft_printo_4(unsigned long h, t_printf p_l, int len, int i)
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
		ft_putstr(ft_itoa_base_long(h, 8));
	return (p_l);
}

t_printf	ft_printo(unsigned long h, t_printf p_l)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(ft_itoa_base_long(h, 8));
	if (p_l.prec == 0 && h == 0 && p_l.nb_t > 0)
		p_l.nb_t++;
	if (p_l.sign_neg > 0)
		p_l = ft_printo_1(h, p_l, len, i);
	else if (p_l.zero > 0 && p_l.prec < 0)
		p_l = ft_printo_2(h, p_l, len, i);
	else
	{
		if ((p_l.ash > 0 && h != 0 && p_l.prec < len)
				|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
			i++;
		if (p_l.prec != 0 || h != 0)
			p_l.ret = p_l.ret + len;
		if (p_l.prec > len)
			p_l = ft_printo_3(h, p_l, len, i);
		else
			p_l = ft_printo_4(h, p_l, len, i);
	}
	return (p_l);
}
