/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:19:16 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:13:15 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_conversion_b(t_printf p_l)
{
	if (p_l.l == 1)
		p_l = ft_printb(va_arg(p_l.ap, unsigned long), p_l);
	else if (p_l.l == 2)
		p_l = ft_printb((unsigned long)va_arg(p_l.ap, unsigned long long), p_l);
	else if (p_l.h == 1)
		p_l = ft_cl_print_s_b((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	else if (p_l.h == 2)
		p_l = ft_cl_print_c_b((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	else
		p_l = ft_cl_print_i_b((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	return (p_l);
}

t_printf	ft_cl_print_i_b(unsigned long h, t_printf p_l)
{
	if (h >= 4294967296)
		h = h % 4294967296;
	return (ft_printb(h, p_l));
}

t_printf	ft_cl_print_s_b(unsigned long h, t_printf p_l)
{
	if (h >= 65536)
		h = h % 65536;
	return (ft_printb(h, p_l));
}

t_printf	ft_cl_print_c_b(unsigned long h, t_printf p_l)
{
	if (h >= 256)
		h = h % 256;
	return (ft_printb(h, p_l));
}

t_printf	ft_printb_1(unsigned long h, t_printf p_l, int len, int i)
{
	if ((p_l.ash > 0 && h != 0)
			|| (h == 0 && p_l.ash > 0 && p_l.prec == 0))
	{
		ft_putchar('0');
		p_l.ret++;
		i++;
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
		ft_putstr(ft_itoa_base_long(h, 2));
	p_l = ft_cl_print_d_3_1(p_l, i, len);
	return (p_l);
}
