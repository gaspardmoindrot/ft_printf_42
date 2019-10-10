/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:37:34 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:31:02 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf		ft_conversion_s(t_printf p_l)
{
	p_l = ft_cl_print_s(va_arg(p_l.ap, const char*), p_l);
	return (p_l);
}

t_printf		ft_cl_p_s_1(const char *h, t_printf p_l, int i)
{
	if (p_l.prec >= 0)
	{
		while (i < p_l.prec && h[i])
		{
			ft_putchar(h[i]);
			i++;
			p_l.ret++;
		}
	}
	else
	{
		while (h[i])
		{
			ft_putchar(h[i]);
			i++;
			p_l.ret++;
		}
	}
	while (i < p_l.nb_t)
	{
		ft_putchar(' ');
		i++;
		p_l.ret++;
	}
	return (p_l);
}

t_printf		ft_cl_p_s_2(const char *h, t_printf p_l, int i)
{
	while (h[i])
	{
		ft_putchar(h[i]);
		i++;
		p_l.ret++;
	}
	return (p_l);
}

t_printf		ft_cl_p_s_3(const char *h, t_printf p_l, int i)
{
	i = 0;
	if (p_l.prec >= 0 && p_l.prec < (int)ft_strlen(h))
		i = p_l.prec;
	else
		i = (int)ft_strlen(h);
	while (i < p_l.nb_t)
	{
		ft_putchar('0');
		i++;
		p_l.ret++;
	}
	i = 0;
	if (p_l.prec >= 0)
	{
		while (i < p_l.prec && h[i])
		{
			ft_putchar(h[i]);
			i++;
			p_l.ret++;
		}
	}
	else
		p_l = ft_cl_p_s_2(h, p_l, i);
	return (p_l);
}

t_printf		ft_cl_p_s_4(const char *h, t_printf p_l, int i)
{
	i = 0;
	if (p_l.prec >= 0 && p_l.prec < (int)ft_strlen(h))
		i = p_l.prec;
	else
		i = (int)ft_strlen(h);
	while (i < p_l.nb_t)
	{
		ft_putchar(' ');
		i++;
		p_l.ret++;
	}
	i = 0;
	if (p_l.prec >= 0)
	{
		while (i < p_l.prec && h[i])
		{
			ft_putchar(h[i]);
			i++;
			p_l.ret++;
		}
	}
	else
		p_l = ft_cl_p_s_2(h, p_l, i);
	return (p_l);
}
