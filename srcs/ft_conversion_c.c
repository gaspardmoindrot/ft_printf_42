/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:32:54 by gmoindro          #+#    #+#             */
/*   Updated: 2019/07/27 12:37:30 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static t_printf	ft_conv_c_1(t_printf p_l)
{
	if (p_l.nb_t > 0)
		p_l.ret = p_l.ret + p_l.nb_t;
	else
		p_l.ret++;
	while (p_l.nb_t > 1)
	{
		ft_putchar('0');
		p_l.nb_t--;
	}
	ft_putchar(va_arg(p_l.ap, int));
	return (p_l);
}

static t_printf	ft_conv_c_2(t_printf p_l)
{
	if (p_l.nb_t > 0)
		p_l.ret = p_l.ret + p_l.nb_t;
	else
		p_l.ret++;
	while (p_l.nb_t > 1)
	{
		ft_putchar(' ');
		p_l.nb_t--;
	}
	ft_putchar(va_arg(p_l.ap, int));
	return (p_l);
}

t_printf		ft_conversion_c(t_printf p_l)
{
	if (p_l.sign_neg > 0)
	{
		ft_putchar(va_arg(p_l.ap, int));
		if (p_l.nb_t > 0)
			p_l.ret = p_l.ret + p_l.nb_t;
		else
			p_l.ret++;
		while (p_l.nb_t > 1)
		{
			ft_putchar(' ');
			p_l.nb_t--;
		}
	}
	else if (p_l.zero > 0)
		p_l = ft_conv_c_1(p_l);
	else
		p_l = ft_conv_c_2(p_l);
	return (p_l);
}
