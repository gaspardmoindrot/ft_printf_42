/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_e.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:31:25 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:51:16 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <float.h>

t_printf	ft_conversion_e(t_printf p_l)
{
	if (p_l.lm >= 1)
		p_l = ft_cl_print_e(va_arg(p_l.ap, long double), p_l);
	else
		p_l = ft_cl_print_e((long double)va_arg(p_l.ap, double), p_l);
	return (p_l);
}

int			ft_zero_plus(long double h)
{
	int	i;

	i = 0;
	if (h > 0)
	{
		while (h < 1)
		{
			h = h * 10;
			i++;
		}
	}
	else
	{
		while (h > -1)
		{
			h = h * 10;
			i++;
		}
	}
	return (i);
}

t_printf	ft_cl_print_e_1(t_printf p_l, long double h, char *str, int r)
{
	int		j;

	j = 0;
	if (p_l.sign_pos > 0 && h > 0)
	{
		ft_putchar('+');
		p_l.ret++;
		j++;
	}
	else if (p_l.space > 0 && h > 0)
	{
		ft_putchar(' ');
		p_l.ret++;
		j++;
	}
	ft_putstr_e(str, ft_print_f_i(p_l), r);
	p_l.ret = p_l.ret + ft_strlen_e(str, ft_print_f_i(p_l));
	while (ft_strlen_e(str, ft_print_f_i(p_l)) + j < p_l.nb_t)
	{
		ft_putchar(' ');
		p_l.ret++;
		j++;
	}
	return (p_l);
}

t_printf	ft_cl_print_e_2(t_printf p_l, long double h, char *str, int r)
{
	int		j;

	j = 0;
	if (p_l.sign_pos > 0 && h > 0)
	{
		ft_putchar('+');
		p_l.ret++;
		j++;
	}
	else if (p_l.space > 0)
	{
		ft_putchar(' ');
		p_l.ret++;
		j++;
	}
	while (ft_strlen_e(str, ft_print_f_i(p_l)) + j < p_l.nb_t)
	{
		ft_putchar('0');
		p_l.ret++;
		j++;
	}
	p_l.ret = p_l.ret + ft_strlen_e(str, ft_print_f_i(p_l));
	ft_putstr_e(str, ft_print_f_i(p_l), r);
	return (p_l);
}

t_printf	ft_cl_print_e_3(t_printf p_l, long double h, char *str, int r)
{
	int		j;

	j = 0;
	if ((p_l.sign_pos > 0 && h > 0) || (p_l.space > 0))
		j++;
	while (ft_strlen_e(str, ft_print_f_i(p_l)) + j < p_l.nb_t)
	{
		ft_putchar(' ');
		p_l.ret++;
		j++;
	}
	if (p_l.sign_pos > 0 && h > 0)
	{
		ft_putchar('+');
		p_l.ret++;
	}
	else if (p_l.space > 0 && h > 0)
	{
		ft_putchar(' ');
		p_l.ret++;
	}
	p_l.ret = p_l.ret + ft_strlen_e(str, ft_print_f_i(p_l));
	ft_putstr_e(str, ft_print_f_i(p_l), r);
	return (p_l);
}
