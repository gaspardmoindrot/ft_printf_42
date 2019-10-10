/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_e_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:50:45 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:51:22 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char		*ft_cl_p4(long double h, int i, long double e, long double d)
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
	str = ft_comp_char_l(str, i, e, d);
	if (h < 0 && h > -1)
		str = ft_comp_inf(str, d, i, 3);
	return (str);
}
