/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 11:25:21 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:38:46 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_end_second(const char *f, t_printf p)
{
	while (f[p.i] == '0')
	{
		p.zero++;
		p.i++;
		p.count++;
	}
	while (f[p.i] == '-')
	{
		p.sign_neg++;
		p.i++;
		p.count++;
	}
	while (f[p.i] == '+')
	{
		p.sign_pos++;
		p.i++;
		p.count++;
	}
	return (ft_end_sec(f, p));
}

t_printf	ft_end_sec(const char *f, t_printf p)
{
	while (f[p.i] == ' ')
	{
		p.space++;
		p.i++;
		p.count++;
	}
	while (f[p.i] == '#')
	{
		p.ash++;
		p.i++;
		p.count++;
	}
	return (p);
}
