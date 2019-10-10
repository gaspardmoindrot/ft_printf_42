/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 11:14:07 by gmoindro          #+#    #+#             */
/*   Updated: 2019/08/11 15:53:07 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <float.h>
# include "../libft/libft.h"

typedef struct	s_printf
{
	int			i;
	int			i_prec;
	int			nb_p;
	va_list		ap;
	int			ret;

	char		ltr;
	int			ash;
	int			zero;
	int			sign_neg;
	int			sign_pos;
	int			space;
	int			nb_t;
	int			prec;
	int			h;
	int			l;
	int			lm;
	int			nb_zero;
	int			count;
}				t_printf;

int				ft_printf(const char *format, ...);
t_printf		ft_printf_init(t_printf printf);
t_printf		ft_putchar_print(const char *format, t_printf printf_l);

t_printf		ft_end(const char *f, t_printf p);
int				ft_puissance(int nb, int h);
t_printf		ft_end_second(const char *f, t_printf p);
t_printf		ft_end_sec(const char *f, t_printf p);
t_printf		ft_end_third(const char *f, t_printf p);
t_printf		ft_end_th(const char *f, t_printf p);
t_printf		ft_end_four(const char *f, t_printf p);
t_printf		ft_end_f(const char *f, t_printf p, int i);
t_printf		ft_end_bonus(const char *f, t_printf p);
t_printf		ft_end_five(const char *f, t_printf p);
int				ft_para(char c);
int				ft_is_letter(char c);

t_printf		ft_classe(t_printf p_l);

t_printf		ft_color(t_printf p_l, const char *f);
t_printf		ft_color_1(t_printf p_l, const char *f);
t_printf		ft_color_2(t_printf p_l, const char *f);
t_printf		ft_color_3(t_printf p_l, const char *f);

t_printf		ft_conversion_c(t_printf p_l);
t_printf		ft_conversion_pourc(t_printf p_l);
t_printf		ft_conversion_s(t_printf p_l);
t_printf		ft_cl_print_s(const char *h, t_printf p_l);
t_printf		ft_cl_p_s_1(const char *h, t_printf p_l, int i);
t_printf		ft_cl_p_s_2(const char *h, t_printf p_l, int i);
t_printf		ft_cl_p_s_3(const char *h, t_printf p_l, int i);
t_printf		ft_cl_p_s_4(const char *h, t_printf p_l, int i);

t_printf		ft_conversion_d(t_printf p_l);
int				len_nb_long(long h);
void			ft_putnbr_long(long n);
t_printf		ft_cl_print_d(long h, t_printf p_l);
t_printf		ft_cl_print_sh_d(long h, t_printf p_l);
t_printf		ft_cl_print_ch_d(long h, t_printf p_l);
t_printf		ft_cl_print_in_d(long h, t_printf p_l);
t_printf		ft_cl_print_d_2_1(int i, t_printf p_l, long h, int len);
t_printf		ft_cl_print_d_3_1(t_printf p_l, int i, int len);
t_printf		ft_sign_p(t_printf p_l, long h);
t_printf		ft_cl_print_d_1(t_printf p_l, long h, int i, int len);
t_printf		ft_cl_print_d_2(t_printf p_l, long h, int i, int len);
t_printf		ft_cl_print_d_3(t_printf p_l, long h, int i, int len);

t_printf		ft_conversion_u(t_printf p_l);
t_printf		ft_cl_print_i_u(unsigned long h, t_printf p_l);
t_printf		ft_cl_print_s_u(unsigned long h, t_printf p_l);
t_printf		ft_cl_print_c_u(unsigned long h, t_printf p_l);
int				len_nb_u_long(unsigned long h);
void			ft_putnbr_u_long(unsigned long n);
t_printf		ft_printu(unsigned long h, t_printf p_l);
t_printf		ft_printu_1(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printu_2(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printu_2_1(unsigned long h, t_printf p_l, int len, int i);

char			*ft_itoa_base_long(unsigned long value, unsigned long base);
t_printf		ft_conversion_o(t_printf p_l);
t_printf		ft_cl_print_i_o(unsigned long h, t_printf p_l);
t_printf		ft_cl_print_s_o(unsigned long h, t_printf p_l);
t_printf		ft_cl_print_c_o(unsigned long h, t_printf p_l);
t_printf		ft_printo(unsigned long h, t_printf p_l);
t_printf		ft_printo_1(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printo_2(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printo_3(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printo_4(unsigned long h, t_printf p_l, int len, int i);

char			*ft_itoa_base_long_x(unsigned long value, unsigned long base);
t_printf		ft_conversion_x(t_printf p_l);
t_printf		ft_cl_print_i_x(unsigned long h, t_printf p_l);
t_printf		ft_cl_print_s_x(unsigned long h, t_printf p_l);
t_printf		ft_cl_print_c_x(unsigned long h, t_printf p_l);
t_printf		ft_printx(unsigned long h, t_printf p_l);
t_printf		ft_printx_1(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printx_2(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printx_3(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printx_4(unsigned long h, t_printf p_l, int len, int i);

t_printf		ft_conversion_x_maj(t_printf p_l);
t_printf		ft_cl_print_i_m(unsigned long h, t_printf p_l);
t_printf		ft_cl_print_s_m(unsigned long h, t_printf p_l);
t_printf		ft_cl_print_c_m(unsigned long h, t_printf p_l);
t_printf		ft_printm(unsigned long h, t_printf p_l);
t_printf		ft_printm_1(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printm_2(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printm_3(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printm_4(unsigned long h, t_printf p_l, int len, int i);

t_printf		ft_conversion_b(t_printf p_l);
t_printf		ft_cl_print_i_b(unsigned long h, t_printf p_l);
t_printf		ft_cl_print_s_b(unsigned long h, t_printf p_l);
t_printf		ft_cl_print_c_b(unsigned long h, t_printf p_l);
t_printf		ft_printb(unsigned long h, t_printf p_l);
t_printf		ft_printb_1(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printb_2(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printb_3(unsigned long h, t_printf p_l, int len, int i);
t_printf		ft_printb_4(unsigned long h, t_printf p_l, int len, int i);

t_printf		ft_conversion_p(t_printf p_l);
void			ft_print_hex(size_t nb);
int				ft_len_hex(size_t nb);
t_printf		ft_cl_print_p(size_t h, t_printf p_l);
t_printf		ft_cl_print_p_3(size_t h, t_printf p_l, int i, int len);
t_printf		ft_cl_print_p_2(size_t h, t_printf p_l, int i, int len);
t_printf		ft_cl_print_p_1(size_t h, t_printf p_l, int i, int len);

char			*ft_comp_char_l(char *str, int i, long double e, long double d);
char			*ft_comp_char_l_1(char *str, int l, long double ent, int i);
t_printf		ft_cl_print_f(long double h, t_printf p_l, int i);
int				ft_print_f_i(t_printf p_l);
long double		ft_dec_f(long double h, long double ent, int i, int j);
char			*ft_cl_f_str(long double h, int i);
long double		ft_long_double_cl(long double h);
long double		ft_simpl(long double dec, int i);
long double		ft_ent_double(long double h, int i);
long double		ft_ent_double_1(long double h, int i);
long double		ft_puissance_do(int i);
int				ft_len_double(long double h);
t_printf		ft_conversion_f(t_printf p_l);
char			*ft_comp_inf(char *str, long double dec, int i, int r);
char			*ft_comp_inf_1(char *str, int i, int r);
t_printf		ft_cl_print_f_3(long double h, t_printf p_l, char *str, int j);
t_printf		ft_cl_print_f_2(long double h, t_printf p_l, char *str);
t_printf		ft_cl_print_f_2_1(long double h, t_printf p_l, char *str);
t_printf		ft_cl_print_f_1(long double h, t_printf p_l, char *str);

t_printf		ft_conversion_e(t_printf p_l);
t_printf		ft_cl_print_e(long double h, t_printf p_l);
int				ft_zero_plus(long double h);
int				ft_strlen_e(char *str, int i);
void			ft_putstr_e(char *str, int i, int j);
void			ft_putstr_e_1(int j);
void			ft_putstr_e_2(char *str, int i);
t_printf		ft_cl_print_e_1(t_printf p_l, long double h, char *str, int r);
t_printf		ft_cl_print_e_2(t_printf p_l, long double h, char *str, int r);
t_printf		ft_cl_print_e_3(t_printf p_l, long double h, char *str, int r);
char			*ft_cl_p4(long double h, int i, long double e, long double d);
t_printf		ft_cl_print_e_5(t_printf p_l, long double h, char *str, int r);
char			*ft_str_en_e_1(int j, char *str, long double h);
int				ft_str_en_e_2(int j, char *str, long double h);
char			*ft_str_en_e_3(int j, char *str, long double h);
int				ft_str_en_e_4(int j, char *str, long double h);

#endif
