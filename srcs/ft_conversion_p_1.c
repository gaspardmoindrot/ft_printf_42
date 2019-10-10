/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:16:49 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:22:13 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_cl_print_p_3(size_t h, t_printf p_l, int i, int len)
{
	ft_putstr("0x");
	i = i + 2;
	p_l.ret = p_l.ret + 2;
	while (len + i < p_l.nb_t)
	{
		ft_putchar('0');
		p_l.ret++;
		i++;
	}
	if (h != 0 || p_l.prec != 0)
		ft_print_hex(h);
	p_l.ret = p_l.ret + len;
	return (p_l);
}

t_printf	ft_cl_print_p(size_t h, t_printf p_l)
{
	int	len;
	int	i;

	i = 0;
	if (h != 0 || p_l.prec != 0)
		len = ft_len_hex(h);
	else
		len = 0;
	if (p_l.sign_neg > 0)
		p_l = ft_cl_print_p_1(h, p_l, i, len);
	else if (p_l.zero > 0 && p_l.prec < 0)
		p_l = ft_cl_print_p_3(h, p_l, i, len);
	else
		p_l = ft_cl_print_p_2(h, p_l, i, len);
	return (p_l);
}
