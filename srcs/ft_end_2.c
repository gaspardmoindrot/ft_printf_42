/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:38:07 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:38:21 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_printf	ft_end_third(const char *f, t_printf p)
{
	int	h;

	h = 0;
	if (f[p.i] > 48 && f[p.i] < 58)
	{
		p.nb_t = 0;
		while (f[p.i] > 47 && f[p.i] < 58)
			p.i++;
		p.i--;
		while (f[p.i] > 47 && f[p.i] < 58)
		{
			p.nb_t = p.nb_t + (f[p.i] - '0') * (ft_puissance(10, h));
			h++;
			p.i--;
		}
		p.i++;
		while (f[p.i] > 47 && f[p.i] < 58)
			p.i++;
		p.count++;
	}
	return (ft_end_th(f, p));
}

t_printf	ft_end_th(const char *f, t_printf p)
{
	int	h;

	h = 0;
	if (f[p.i] == '.')
	{
		p.prec = 0;
		p.i++;
		while (f[p.i] > 47 && f[p.i] < 58)
			p.i++;
		p.i--;
		while (f[p.i] > 47 && f[p.i] < 58)
		{
			p.prec = p.prec + (f[p.i] - '0') * (ft_puissance(10, h));
			h++;
			p.i--;
		}
		p.i++;
		while (f[p.i] > 47 && f[p.i] < 58)
			p.i++;
		p.count++;
	}
	return (p);
}

t_printf	ft_end_four(const char *f, t_printf p)
{
	if (f[p.i] == 'h')
	{
		if (f[p.i] == 'h' && f[p.i + 1] == 'h')
		{
			p.i++;
			p.h = 2;
		}
		else if (f[p.i] == 'h')
			p.h = 1;
		p.i++;
		p.count++;
	}
	else if (f[p.i] == 'l')
	{
		if (f[p.i] == 'l' && f[p.i + 1] == 'l')
		{
			p.i++;
			p.l = 2;
		}
		else if (f[p.i] == 'l')
			p.l = 1;
		p.i++;
		p.count++;
	}
	return (ft_end_f(f, p, 0));
}

t_printf	ft_end_f(const char *f, t_printf p, int i)
{
	if (i == 0)
	{
		if (f[p.i] == 'L')
		{
			p.lm = 1;
			p.i++;
			p.count++;
		}
		return (p);
	}
	if (p.i_prec == 0)
		p.i_prec = p.i;
	p.i++;
	return (p);
}

t_printf	ft_end_bonus(const char *f, t_printf p)
{
	if (f[p.i] == '*')
	{
		if (f[p.i - 1] != '.')
		{
			p.nb_t = va_arg(p.ap, int);
			if (p.nb_t < 0)
			{
				p.nb_t = -p.nb_t;
				p.sign_neg++;
			}
			p.count++;
			p.i++;
		}
		else
		{
			p.prec = va_arg(p.ap, int);
			if (p.prec < 0)
				p.prec = -1;
			p.count++;
			p.i++;
		}
	}
	return (p);
}
