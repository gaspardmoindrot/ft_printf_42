/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 11:59:09 by gmoindro          #+#    #+#             */
/*   Updated: 2019/07/27 12:31:34 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	size(unsigned long nb, int base)
{
	int		len;

	len = 0;
	while (nb > 0)
	{
		len++;
		nb = nb / base;
	}
	return (len);
}

static char	*ft_put_nb(int j)
{
	char	c;
	char	*tab;
	int		i;

	i = 0;
	c = '0';
	if (!(tab = (char*)malloc(sizeof(char) * 16)))
		return (NULL);
	while (c <= '9')
	{
		tab[i] = c;
		i++;
		c++;
	}
	c = 'A' + j;
	while (c <= 'F' + j)
	{
		tab[i] = c;
		i++;
		c++;
	}
	return (tab);
}

char		*ft_itoa_base_long(unsigned long value, unsigned long base)
{
	char			*str;
	char			*tab;
	int				i;
	int				o;
	unsigned long	nb;

	tab = ft_put_nb(0);
	nb = value;
	i = size(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		return ("0\0");
	while (nb > 0)
	{
		o = nb % base;
		str[i] = tab[o];
		nb = nb / base;
		i--;
	}
	free(tab);
	free(str);
	return (str);
}

char		*ft_itoa_base_long_x(unsigned long value, unsigned long base)
{
	char			*str;
	char			*tab;
	int				i;
	int				o;
	unsigned long	nb;

	tab = ft_put_nb(32);
	nb = value;
	i = size(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		return ("0\0");
	while (nb > 0)
	{
		o = nb % base;
		str[i] = tab[o];
		nb = nb / base;
		i--;
	}
	free(tab);
	free(str);
	return (str);
}
