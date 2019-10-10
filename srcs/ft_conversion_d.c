/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:03:33 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:31:04 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf		ft_conversion_d(t_printf p_l)
{
	if (p_l.l == 1)
		p_l = ft_cl_print_d(va_arg(p_l.ap, long), p_l);
	else if (p_l.l == 2)
		p_l = ft_cl_print_d((long)va_arg(p_l.ap, long long), p_l);
	else if (p_l.h == 1)
		p_l = ft_cl_print_sh_d((long)va_arg(p_l.ap, int), p_l);
	else if (p_l.h == 2)
		p_l = ft_cl_print_ch_d((long)va_arg(p_l.ap, int), p_l);
	else
		p_l = ft_cl_print_in_d((long)va_arg(p_l.ap, int), p_l);
	return (p_l);
}

t_printf		ft_cl_print_in_d(long h, t_printf p_l)
{
	if (h >= 0)
	{
		if (h >= 4294967294)
			h = h % 65536;
		if (h >= 2147483648)
			h = -2147483648 + (-2147483648 + h);
	}
	else
	{
		if (h <= -4294967294)
			h = h % 2147483648;
		if (h < -2147483648)
			h = 2147483648 - (-2147483648 - h);
	}
	return (ft_cl_print_d(h, p_l));
}

t_printf		ft_cl_print_sh_d(long h, t_printf p_l)
{
	if (h >= 0)
	{
		if (h >= 65536)
			h = h % 65536;
		if (h >= 32768)
			h = -32768 + (-32768 + h);
	}
	else
	{
		if (h <= -65536)
			h = h % 65536;
		if (h < -32768)
			h = 32767 - (-32769 - h);
	}
	return (ft_cl_print_d(h, p_l));
}

t_printf		ft_cl_print_s(const char *h, t_printf p_l)
{
	int i;

	i = 0;
	if (h == NULL)
		return (ft_cl_print_s("(null)", p_l));
	if (p_l.sign_neg > 0)
		p_l = ft_cl_p_s_1(h, p_l, i);
	else if (p_l.zero > 0)
		p_l = ft_cl_p_s_3(h, p_l, i);
	else
		p_l = ft_cl_p_s_4(h, p_l, i);
	return (p_l);
}
