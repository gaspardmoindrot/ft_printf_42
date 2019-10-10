/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_f_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:42:18 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:45:20 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_cl_print_f_2_1(long double h, t_printf p_l, char *str)
{
	if (str[0] == '-')
		ft_putchar('-');
	else if (p_l.sign_pos > 0 && h > 0)
	{
		ft_putchar('+');
		p_l.ret++;
	}
	else if (p_l.space > 0)
	{
		ft_putchar(' ');
		p_l.ret++;
	}
	return (p_l);
}

t_printf	ft_cl_print_f_2(long double h, t_printf p_l, char *str)
{
	int j;

	j = 0;
	p_l = ft_cl_print_f_2_1(h, p_l, str);
	if (str[0] != '-' && ((p_l.sign_pos > 0 && h > 0) || p_l.space > 0))
		j++;
	while ((int)ft_strlen(str) + j < p_l.nb_t)
	{
		ft_putchar('0');
		p_l.ret++;
		j++;
	}
	p_l.ret = p_l.ret + (int)ft_strlen(str);
	if (str[0] != '-')
		ft_putstr(str);
	else
	{
		j = 1;
		while (str[j])
		{
			ft_putchar(str[j]);
			j++;
		}
	}
	return (p_l);
}

t_printf	ft_cl_print_f_3(long double h, t_printf p_l, char *str, int j)
{
	if (p_l.sign_pos > 0 && h > 0)
		j++;
	else if (p_l.space > 0)
		j++;
	while ((int)ft_strlen(str) + j < p_l.nb_t)
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
	p_l.ret = p_l.ret + (int)ft_strlen(str);
	ft_putstr(str);
	return (p_l);
}

int			ft_print_f_i(t_printf p_l)
{
	int	i;

	if (p_l.prec > 0)
		i = p_l.prec + 1;
	else if (p_l.prec == 0 && p_l.ash == 0)
		i = 0;
	else if (p_l.prec == 0 && p_l.ash > 0)
		i = 1;
	else
		i = 7;
	return (i);
}

long double	ft_long_double_cl(long double h)
{
	long double ent;

	if (h != LDBL_MAX && h != LDBL_MIN)
		ent = ft_ent_double(h, ft_len_double(h));
	else if (h == LDBL_MAX)
		ent = LDBL_MAX;
	else
		ent = LDBL_MIN;
	return (ent);
}
