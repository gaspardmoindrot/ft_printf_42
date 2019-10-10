/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_f_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:45:24 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:45:51 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

long double	ft_ent_double(long double h, int i)
{
	long double	end;
	long double	end2;

	end = 0;
	if (h >= 0)
		return (ft_ent_double_1(h, i));
	else
	{
		i--;
		while (i > 0)
		{
			while (end >= h)
			{
				end = end - ft_puissance_do(i);
				if (end == end2)
					break ;
				end2 = end;
			}
			end = end + ft_puissance_do(i);
			i--;
		}
	}
	return (end);
}

long double	ft_simpl(long double dec, int i)
{
	long double	l;
	long double	l_2;
	long double	dec_2;

	dec_2 = dec;
	l = 1;
	while (i > 0)
	{
		l = l / 10;
		l_2 = l;
		while (l_2 <= dec_2)
			l_2 = l_2 + l;
		l_2 = l_2 - l;
		dec_2 = dec_2 - l_2;
		i--;
	}
	l = l / 2;
	dec = dec - dec_2;
	if (l < dec_2)
		dec = dec + (l * 2);
	return (dec);
}

char		*ft_comp_inf_1(char *str, int i, int r)
{
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '-' && str[i] != '.')
			r = 0;
		i++;
	}
	if (r != 0)
		str[1] = '1';
	return (str);
}

char		*ft_comp_inf(char *str, long double dec, int i, int r)
{
	long double	l;
	char		c;

	l = 1;
	str[i + 2] = '\0';
	str[0] = '-';
	str[1] = '0';
	if (i > 0)
		str[2] = '.';
	while (i - 1 > 0)
	{
		l = l / 10;
		c = '0';
		while (dec >= 0 || (dec < 0 && dec > -0.0000000000000001))
		{
			c++;
			dec = dec - l;
		}
		c--;
		dec = dec + l;
		str[r] = c;
		r++;
		i--;
	}
	return (ft_comp_inf_1(str, i, r));
}

t_printf	ft_cl_print_f_1(long double h, t_printf p_l, char *str)
{
	int	j;

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
	ft_putstr(str);
	p_l.ret = p_l.ret + (int)ft_strlen(str);
	while ((int)ft_strlen(str) + j < p_l.nb_t)
	{
		ft_putchar(' ');
		p_l.ret++;
		j++;
	}
	return (p_l);
}
