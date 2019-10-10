/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_d_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:26:10 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:28:18 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf		ft_cl_print_ch_d(long h, t_printf p_l)
{
	if (h >= 0)
	{
		if (h >= 256)
			h = h % 256;
		if (h >= 128)
			h = -128 + (-128 + h);
	}
	else
	{
		if (h <= -256)
			h = h % 256;
		if (h < -128)
			h = 127 - (-129 - h);
	}
	return (ft_cl_print_d(h, p_l));
}

int				len_nb_long(long h)
{
	int	count;

	count = 1;
	if (h < 0)
		h = -h;
	while (h > 9)
	{
		h = h / 10;
		count++;
	}
	return (count);
}

void			ft_putnbr_long(long n)
{
	if (n < 0)
		n = -n;
	if (n > 9)
	{
		ft_putnbr_long(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

t_printf		ft_sign_p(t_printf p_l, long h)
{
	if (p_l.sign_pos > 0 && h >= 0)
	{
		ft_putchar('+');
		p_l.ret++;
	}
	else if (h < 0)
	{
		ft_putchar('-');
		p_l.ret++;
	}
	else if (p_l.space > 0)
	{
		ft_putchar(' ');
		p_l.ret++;
	}
	return (p_l);
}

t_printf		ft_cl_print_d_1(t_printf p_l, long h, int i, int len)
{
	if ((p_l.sign_pos > 0 && h >= 0) || (h < 0) || (p_l.space > 0))
		i++;
	p_l = ft_sign_p(p_l, h);
	p_l.ret = p_l.ret + len;
	while ((len + i) < p_l.nb_t)
	{
		ft_putchar('0');
		p_l.ret++;
		len++;
	}
	if (h < -9223372036854775807)
		ft_putstr("9223372036854775808");
	else
		ft_putnbr_long(h);
	return (p_l);
}
