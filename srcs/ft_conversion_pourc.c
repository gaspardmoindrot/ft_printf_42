/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pourc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:22:04 by gmoindro          #+#    #+#             */
/*   Updated: 2019/07/27 13:26:47 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static t_printf	ft_conv_pour_1(t_printf p_l)
{
	ft_putchar('%');
	if (p_l.nb_t > 0)
		p_l.ret = p_l.ret + p_l.nb_t;
	else
		p_l.ret++;
	while (p_l.nb_t > 1)
	{
		ft_putchar(' ');
		p_l.nb_t--;
	}
	return (p_l);
}

static t_printf	ft_conv_pour_2(t_printf p_l)
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
	ft_putchar('%');
	return (p_l);
}

t_printf		ft_conversion_pourc(t_printf p_l)
{
	if (p_l.sign_neg > 0)
		p_l = ft_conv_pour_1(p_l);
	else if (p_l.zero > 0)
		p_l = ft_conv_pour_2(p_l);
	else
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
		ft_putchar('%');
	}
	return (p_l);
}
