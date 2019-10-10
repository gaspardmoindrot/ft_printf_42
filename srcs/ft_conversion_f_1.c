/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_f_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:40:47 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:42:15 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char		*ft_cl_f_str(long double h, int i)
{
	int		long_ent;
	char	*str;

	long_ent = ft_len_double(h);
	str = (char *)malloc(sizeof(char) * (i + long_ent + 1));
	if (!str)
		return (NULL);
	str[i + long_ent] = '\0';
	while (i + long_ent >= 1)
	{
		str[i + long_ent - 1] = '0';
		long_ent--;
	}
	if (i > 0)
		str[ft_len_double(h)] = '.';
	if (h < 0)
		str[0] = '-';
	return (str);
}

long double	ft_dec_f(long double h, long double ent, int i, int j)
{
	long double dec;

	dec = h - ent;
	if (dec < 0)
		dec = -dec;
	dec = ft_simpl(dec, i - 1);
	if (dec >= 1)
	{
		if (ent >= 0)
			ent++;
		else
			ent--;
		dec--;
	}
	if (j == 0)
		return (dec);
	else
		return (ent);
}

t_printf	ft_cl_print_f(long double h, t_printf p_l, int i)
{
	long double	ent;
	long double	dec;
	char		*str;

	i = ft_print_f_i(p_l);
	ent = ft_long_double_cl(h);
	dec = ft_dec_f(h, ent, i, 0);
	ent = ft_dec_f(h, ent, i, 1);
	str = ft_cl_f_str(h, i);
	str = ft_comp_char_l(str, i, ent, dec);
	if (h < 0 && h > -1)
		str = ft_comp_inf(str, dec, i, 3);
	if (p_l.sign_neg > 0)
		p_l = ft_cl_print_f_1(h, p_l, str);
	else if (p_l.zero > 0)
		p_l = ft_cl_print_f_2(h, p_l, str);
	else
		p_l = ft_cl_print_f_3(h, p_l, str, 0);
	free(str);
	return (p_l);
}

char		*ft_comp_char_l(char *str, int i, long double ent, long double dec)
{
	long double	l;
	char		c;
	int			i_2;
	int			long_ent;

	long_ent = ft_len_double(ent);
	i_2 = i;
	l = 1;
	while (long_ent < ft_len_double(ent) + i - 1)
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
		str[long_ent + 1] = c;
		long_ent++;
	}
	return (ft_comp_char_l_1(str, ft_len_double(ent), ent, 0));
}

char		*ft_comp_char_l_1(char *str, int long_ent, long double ent, int i)
{
	long double l;
	char		c;
	int			long_ent2;

	long_ent2 = long_ent;
	if (ent < 0)
	{
		ent = -ent;
		i++;
		long_ent--;
	}
	while (i < long_ent2)
	{
		l = ft_puissance_do(long_ent);
		c = '0';
		while (ent >= 0)
		{
			c++;
			ent = ent - l;
		}
		str[i++] = --c;
		long_ent--;
		ent = ent + l;
	}
	return (str);
}
