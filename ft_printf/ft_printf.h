/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:20:24 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/05 18:05:31 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\x1B[37m"
# define EOC		"\x1b[0m"

typedef struct	s_arg
{
	char		flag[5];
	int			wd;
	int			precision;
	char		lenth[6];
	char		spec;
}				t_arg;

int				ft_printf(const	char *format, ...);
void			set_struct(t_arg *cur_arg);
char			*joinf(char *str, char *str2);
char			*intoa(intmax_t n);
void			go_print(t_arg *cur_arg, va_list ap, int *res);
void			go_print_char(t_arg *cur_arg, va_list ap, int *res);
void			go_print_c(t_arg *cur_arg, char x, int *res);
void			go_print_cm(t_arg *cur_arg, char x, int *res);
void			go_print_str(t_arg *cur_arg, char *str, int *res);
void			go_print_strm(t_arg *cur_arg, char *str, int *res);
void			go_print_str_pre(t_arg *cur_arg, va_list ap, int *res);
void			go_print_str_pre_s(t_arg *cur_arg, va_list ap, int *res);
void			go_print_d(t_arg *c_a, char *d, int *res, intmax_t di);
void			go_print_dm(t_arg *c_a, char *d, int *res, intmax_t di);
void			go_print_d_pre(t_arg *cur_arg, va_list ap, int *res);
char			*go_print_d_pre_two(t_arg *cur_arg, intmax_t dg);
void			go_print_x(t_arg *cur_arg, char *d, int *res);
void			go_print_xm(t_arg *cur_arg, char *d, int *res);
void			go_print_x_pre(t_arg *cur_arg, va_list ap, int *res);
char			*go_print_x_pre_two(t_arg *cur_arg, unsigned long long int dg);
void			go_print_u(t_arg *c_a, char *d, int *res,
	unsigned long long int di);
void			go_print_um(t_arg *c_a, char *d, int *res,
	unsigned long long int di);
char			*go_print_u_pre_two(t_arg *cur_arg, unsigned long long int dg);
void			go_print_u_pre(t_arg *cur_arg, va_list ap, int *res);
void			go_print_o(t_arg *cur_arg, char *d, int *res);
void			go_print_om(t_arg *cur_arg, char *d, int *res);
char			*go_print_o_pre_two(t_arg *cur_arg, unsigned long long int dg);
void			go_print_o_pre(t_arg *cur_arg, va_list ap, int *res);
void			go_print_p_pre(t_arg *cur_arg, va_list ap, int *res);
void			go_proc_n(va_list ap, int *res);
void			go_print_b(t_arg *cur_arg, va_list ap, int *res);
char			nonspecc(char c);
int				isspec(char c);
int				isformat(char c);
int				isvalid(char x);
int				islenth(char c);
void			fillflag(char *str, t_arg *cur_arg);
int				filllenth(char a, char b, char *str);
void			fill_w_p(char *str, t_arg *cur_arr, va_list ap);
char			*itoa_base(unsigned long long int num, int base);
void			capitalize(char *str);
#endif
