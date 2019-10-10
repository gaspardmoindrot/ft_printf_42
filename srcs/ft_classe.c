/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_classe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:32:01 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:07:39 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_classe(t_printf p_l)
{
	if (p_l.ltr == 'c')
		return (ft_conversion_c(p_l));
	else if (p_l.ltr == 's')
		return (ft_conversion_s(p_l));
	else if (p_l.ltr == 'p')
		return (ft_conversion_p(p_l));
	else if (p_l.ltr == 'd' || p_l.ltr == 'i')
		return (ft_conversion_d(p_l));
	else if (p_l.ltr == 'o')
		return (ft_conversion_o(p_l));
	else if (p_l.ltr == 'u')
		return (ft_conversion_u(p_l));
	else if (p_l.ltr == 'x')
		return (ft_conversion_x(p_l));
	else if (p_l.ltr == 'X')
		return (ft_conversion_x_maj(p_l));
	else if (p_l.ltr == 'f')
		return (ft_conversion_f(p_l));
	else if (p_l.ltr == '%')
		return (ft_conversion_pourc(p_l));
	else if (p_l.ltr == 'b')
		return (ft_conversion_b(p_l));
	else if (p_l.ltr == 'e')
		return (ft_conversion_e(p_l));
	return (p_l);
}
