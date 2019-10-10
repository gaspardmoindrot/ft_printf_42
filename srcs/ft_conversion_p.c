/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:52:52 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:22:15 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_conversion_p(t_printf p_l)
{
	p_l = ft_cl_print_p((size_t)va_arg(p_l.ap, void *), p_l);
	return (p_l);
}

void		ft_print_hex(size_t nb)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= 16)
		ft_print_hex(nb / 16);
	ft_putchar(str[nb % 16]);
}

int			ft_len_hex(size_t nb)
{
	int	count;

	count = 1;
	while (nb > 15)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

t_printf	ft_cl_print_p_1(size_t h, t_printf p_l, int i, int len)
{
	ft_putstr("0x");
	i = i + 2;
	p_l.ret = p_l.ret + 2;
	p_l.ret = p_l.ret + len;
	while (len < p_l.prec)
	{
		ft_putchar('0');
		p_l.ret++;
		len++;
	}
	if (h != 0 || p_l.prec != 0)
		ft_print_hex(h);
	i = i + len;
	while (i < p_l.nb_t)
	{
		ft_putchar(' ');
		p_l.ret++;
		i++;
	}
	return (p_l);
}

t_printf	ft_cl_print_p_2(size_t h, t_printf p_l, int i, int len)
{
	i = i + 2;
	p_l.ret = p_l.ret + len;
	if (len < p_l.prec)
		len = p_l.prec;
	while (len + i < p_l.nb_t)
	{
		ft_putchar(' ');
		p_l.ret++;
		i++;
	}
	ft_putstr("0x");
	p_l.ret = p_l.ret + 2;
	if (h != 0 || p_l.prec != 0)
		len = ft_len_hex(h);
	while (len < p_l.prec)
	{
		ft_putchar('0');
		p_l.ret++;
		len++;
	}
	if (h != 0 || p_l.prec != 0)
		ft_print_hex(h);
	return (p_l);
}
