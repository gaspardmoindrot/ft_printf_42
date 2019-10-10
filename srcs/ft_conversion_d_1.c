/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_d_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:25:01 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:26:01 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf		ft_cl_print_d_2_1(int i, t_printf p_l, long h, int len)
{
	while ((i + p_l.prec) < p_l.nb_t)
	{
		ft_putchar(' ');
		i++;
		p_l.ret++;
	}
	p_l = ft_sign_p(p_l, h);
	while (len < p_l.prec)
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

t_printf		ft_cl_print_d_2(t_printf p_l, long h, int i, int len)
{
	if ((p_l.sign_pos > 0 && h >= 0) || (h < 0) || (p_l.space > 0))
		i++;
	if (p_l.prec != 0 || h != 0)
		p_l.ret = p_l.ret + len;
	if (p_l.prec > len)
		p_l = ft_cl_print_d_2_1(i, p_l, h, len);
	else
	{
		while ((i + len) < p_l.nb_t)
		{
			ft_putchar(' ');
			i++;
			p_l.ret++;
		}
		p_l = ft_sign_p(p_l, h);
		if (h < -9223372036854775807)
			ft_putstr("9223372036854775808");
		else if (p_l.prec != 0 || h != 0)
			ft_putnbr_long(h);
	}
	return (p_l);
}

t_printf		ft_cl_print_d_3_1(t_printf p_l, int i, int len)
{
	if (len > p_l.prec)
	{
		while (i + len < p_l.nb_t)
		{
			i++;
			ft_putchar(' ');
			p_l.ret++;
		}
	}
	else
	{
		while (i + p_l.prec < p_l.nb_t)
		{
			i++;
			ft_putchar(' ');
			p_l.ret++;
		}
	}
	return (p_l);
}

t_printf		ft_cl_print_d_3(t_printf p_l, long h, int i, int len)
{
	if ((p_l.sign_pos > 0 && h >= 0) || (h < 0) || (p_l.space > 0))
		i++;
	p_l = ft_sign_p(p_l, h);
	if (p_l.prec != 0 || h != 0)
		p_l.ret = p_l.ret + len;
	while (len < p_l.prec)
	{
		ft_putchar('0');
		p_l.ret++;
		len++;
	}
	if (h < -9223372036854775807)
		ft_putstr("9223372036854775808");
	else if (p_l.prec != 0 || h != 0)
		ft_putnbr_long(h);
	p_l = ft_cl_print_d_3_1(p_l, i, len);
	return (p_l);
}

t_printf		ft_cl_print_d(long h, t_printf p_l)
{
	int	i;
	int	len;

	if (h < -9223372036854775807)
		len = 19;
	else
		len = len_nb_long(h);
	i = 0;
	if (p_l.prec == 0 && h == 0 && p_l.nb_t > 0)
		p_l.nb_t++;
	if (p_l.sign_neg > 0)
		p_l = ft_cl_print_d_3(p_l, h, i, len);
	else if (p_l.zero > 0 && p_l.prec < 0)
		p_l = ft_cl_print_d_1(p_l, h, i, len);
	else
		p_l = ft_cl_print_d_2(p_l, h, i, len);
	return (p_l);
}
