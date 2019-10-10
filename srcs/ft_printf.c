/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 11:14:52 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:08:42 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			ft_printf(const char *format, ...)
{
	t_printf	printf_l;

	va_start(printf_l.ap, format);
	printf_l.i = 0;
	printf_l.ret = 0;
	while (format[printf_l.i] != '\0')
	{
		printf_l = ft_printf_init(printf_l);
		if (format[printf_l.i] == '%')
		{
			printf_l = ft_end(format, printf_l);
			if (printf_l.ltr != ' ')
				printf_l = ft_classe(printf_l);
			else
				printf_l.i--;
		}
		else if (format[printf_l.i] == '{')
			printf_l = ft_color(printf_l, format);
		else
			printf_l = ft_putchar_print(format, printf_l);
		printf_l.i++;
	}
	va_end(printf_l.ap);
	return (printf_l.ret);
}

t_printf	ft_putchar_print(const char *format, t_printf printf_l)
{
	printf_l.ret++;
	ft_putchar(format[printf_l.i]);
	return (printf_l);
}

t_printf	ft_printf_init(t_printf printf)
{
	printf.ltr = ' ';
	printf.ash = 0;
	printf.zero = 0;
	printf.sign_neg = 0;
	printf.sign_pos = 0;
	printf.space = 0;
	printf.nb_t = 0;
	printf.prec = -1;
	printf.h = 0;
	printf.l = 0;
	printf.lm = 0;
	return (printf);
}
