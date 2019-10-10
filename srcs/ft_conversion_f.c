/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:26:55 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:49:00 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_conversion_f(t_printf p_l)
{
	int	i;

	i = 0;
	if (p_l.lm >= 1)
		p_l = ft_cl_print_f(va_arg(p_l.ap, long double), p_l, i);
	else
		p_l = ft_cl_print_f((long double)va_arg(p_l.ap, double), p_l, i);
	return (p_l);
}

int			ft_len_double(long double h)
{
	int	count;

	count = 1;
	if (h < 0)
	{
		count++;
		h = -h;
	}
	while (h >= 10)
	{
		h = h / 10;
		count++;
	}
	return (count);
}

long double	ft_puissance_do(int i)
{
	long double	h;

	h = 1;
	while (i > 1)
	{
		h = h * 10;
		i--;
	}
	return (h);
}

long double	ft_ent_double_1(long double h, int i)
{
	long double end;
	long double end2;

	end = 0;
	while (i > 0)
	{
		while (end <= h)
		{
			end = end + ft_puissance_do(i);
			if (end == end2)
				break ;
			end2 = end;
		}
		end = end - ft_puissance_do(i);
		i--;
	}
	return (end);
}
