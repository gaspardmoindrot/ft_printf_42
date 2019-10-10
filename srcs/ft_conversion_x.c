/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:12:15 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:35:27 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_conversion_x(t_printf p_l)
{
	if (p_l.l == 1)
		p_l = ft_printx(va_arg(p_l.ap, unsigned long), p_l);
	else if (p_l.l == 2)
		p_l = ft_printx((unsigned long)va_arg(p_l.ap, unsigned long long), p_l);
	else if (p_l.h == 1)
		p_l = ft_cl_print_s_x((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	else if (p_l.h == 2)
		p_l = ft_cl_print_c_x((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	else
		p_l = ft_cl_print_i_x((unsigned long)va_arg(p_l.ap, unsigned int), p_l);
	return (p_l);
}

t_printf	ft_cl_print_i_x(unsigned long h, t_printf p_l)
{
	if (h >= 4294967296)
		h = h % 4294967296;
	return (ft_printx(h, p_l));
}

t_printf	ft_cl_print_s_x(unsigned long h, t_printf p_l)
{
	if (h >= 65536)
		h = h % 65536;
	return (ft_printx(h, p_l));
}

t_printf	ft_cl_print_c_x(unsigned long h, t_printf p_l)
{
	if (h >= 256)
		h = h % 256;
	return (ft_printx(h, p_l));
}
