/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:37:05 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:37:33 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_end(const char *f, t_printf p)
{
	p.i++;
	p.i_prec = 0;
	while (f[p.i])
	{
		p.count = 0;
		p = ft_end_second(f, p);
		p = ft_end_third(f, p);
		p = ft_end_four(f, p);
		p = ft_end_bonus(f, p);
		if (ft_is_letter(f[p.i]) == 1)
			return (ft_end_five(f, p));
		if (f[p.i] == '\0' || f[p.i + 1] == '\0')
		{
			if (p.i_prec != 0)
				p.i = p.i_prec;
			else if (ft_para(f[p.i]) == 1)
				p.i++;
			break ;
		}
		if (p.count == 0)
			p = ft_end_f(f, p, 1);
	}
	return (p);
}

t_printf	ft_end_five(const char *f, t_printf p)
{
	if (f[p.i] == '%' && p.i_prec != 0)
	{
		p.i = p.i_prec;
		return (p);
	}
	p.ltr = f[p.i];
	return (p);
}

int			ft_is_letter(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%'
			|| c == 'b' || c == 'e')
		return (1);
	return (0);
}

int			ft_para(char c)
{
	if ((c > 47 && c < 58) || c == '#' || c == '-' || c == '+'
			|| c == ' ' || c == '.' || c == 'h' || c == 'l'
			|| c == 'L')
		return (1);
	return (0);
}

int			ft_puissance(int nb, int h)
{
	int	result;

	result = 1;
	while (h > 0)
	{
		result = result * nb;
		h--;
	}
	return (result);
}
