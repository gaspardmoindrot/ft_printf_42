/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_e_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:48:47 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:51:52 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			ft_str_en_e_2(int j, char *str, long double h)
{
	int		r;

	r = 0;
	while (j > 1)
	{
		j--;
		r++;
	}
	if (h < 1)
	{
		j++;
		while (str[ft_zero_plus(h) + j])
			j++;
		r = -ft_zero_plus(h);
	}
	return (r);
}

void		ft_putstr_e_1(int j)
{
	if (j >= 0)
	{
		ft_putchar('+');
		if (j < 10)
		{
			ft_putchar('0');
			ft_putnbr(j);
		}
		else
			ft_putnbr(j);
	}
	else
	{
		ft_putchar('-');
		if (j > -10)
		{
			ft_putchar('0');
			ft_putnbr(-j);
		}
		else
			ft_putnbr(-j);
	}
}

void		ft_putstr_e_2(char *str, int i)
{
	int		r;

	r = 2;
	ft_putchar(str[0]);
	ft_putchar(str[1]);
	while (i > 0)
	{
		ft_putchar(str[r]);
		r++;
		i--;
	}
}

void		ft_putstr_e(char *str, int i, int j)
{
	int	r;

	if (str[0] != '-')
	{
		r = 1;
		ft_putchar(str[0]);
		while (i > 0)
		{
			ft_putchar(str[r]);
			r++;
			i--;
		}
	}
	else
		ft_putstr_e_2(str, i);
	ft_putchar('e');
	ft_putstr_e_1(j);
}

int			ft_strlen_e(char *str, int i)
{
	int	count;

	count = 0;
	if (str[0] != '-')
	{
		count++;
		count = count + i;
	}
	else
	{
		count = count + 2;
		count = count + i;
	}
	count = count + 4;
	return (count);
}
