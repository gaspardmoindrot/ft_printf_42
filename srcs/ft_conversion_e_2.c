/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_e_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:49:39 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:53:05 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf		ft_cl_print_e_5(t_printf p_l, long double h, char *str, int r)
{
	if (p_l.sign_neg > 0)
		p_l = ft_cl_print_e_1(p_l, h, str, r);
	else if (p_l.zero > 0)
		p_l = ft_cl_print_e_2(p_l, h, str, r);
	else
		p_l = ft_cl_print_e_3(p_l, h, str, r);
	return (p_l);
}

t_printf		ft_cl_print_e(long double h, t_printf p_l)
{
	char		*str;
	int			i;
	long double	ent;
	long double	dec;
	int			r;

	i = ft_print_f_i(p_l) + ft_zero_plus(h);
	ent = ft_long_double_cl(h);
	dec = ft_dec_f(h, ent, i, 0);
	ent = ft_dec_f(h, ent, i, 1);
	str = ft_cl_p4(h, i, ent, dec);
	if (h > 0)
	{
		r = ft_str_en_e_2(ft_len_double(h), str, h);
		str = ft_str_en_e_1(ft_len_double(h), str, h);
	}
	else
	{
		r = ft_str_en_e_4(ft_len_double(h), str, h);
		str = ft_str_en_e_3(ft_len_double(h), str, h);
	}
	p_l = ft_cl_print_e_5(p_l, h, str, r);
	free(str);
	return (p_l);
}

char			*ft_str_en_e_3(int j, char *str, long double h)
{
	int	r;

	r = 0;
	while (j > 2)
	{
		str[j] = str[j - 1];
		str[j - 1] = '.';
		j--;
		r++;
	}
	if (h > -1)
	{
		str[1] = str[ft_zero_plus(h) + 2];
		str[ft_zero_plus(h) + 2] = '0';
		j++;
		while (str[ft_zero_plus(h) + j])
		{
			str[j] = str[ft_zero_plus(h) + j];
			str[ft_zero_plus(h) + j] = '0';
			j++;
		}
		r = -ft_zero_plus(h);
	}
	return (str);
}

int				ft_str_en_e_4(int j, char *str, long double h)
{
	int r;

	r = 0;
	while (j > 2)
	{
		j--;
		r++;
	}
	if (h > -1)
	{
		j++;
		while (str[ft_zero_plus(h) + j])
			j++;
		r = -ft_zero_plus(h);
	}
	return (r);
}

char			*ft_str_en_e_1(int j, char *str, long double h)
{
	int	r;

	r = 0;
	while (j > 1)
	{
		str[j] = str[j - 1];
		str[j - 1] = '.';
		j--;
		r++;
	}
	if (h < 1)
	{
		str[0] = str[ft_zero_plus(h) + 1];
		str[ft_zero_plus(h) + 1] = '0';
		j++;
		while (str[ft_zero_plus(h) + j])
		{
			str[j] = str[ft_zero_plus(h) + j];
			str[ft_zero_plus(h) + j] = '0';
			j++;
		}
		r = -ft_zero_plus(h);
	}
	return (str);
}
