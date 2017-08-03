/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:49:32 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/04 21:41:22 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

void	go_print(t_arg *c_a, va_list ap, int *res)
{
	if (c_a->spec == '\0')
		return ;
	if (c_a->spec == 'c' || c_a->spec == 'C')
		go_print_char(c_a, ap, res);
	if (c_a->spec == 's')
		go_print_str_pre(c_a, ap, res);
	if (c_a->spec == 'S')
		go_print_str_pre_s(c_a, ap, res);
	if (c_a->spec == 'd' || c_a->spec == 'D' || c_a->spec == 'i')
		go_print_d_pre(c_a, ap, res);
	if (c_a->spec == 'x' || c_a->spec == 'X')
		go_print_x_pre(c_a, ap, res);
	if (c_a->spec == 'u' || c_a->spec == 'U')
		go_print_u_pre(c_a, ap, res);
	if (c_a->spec == 'o' || c_a->spec == 'O')
		go_print_o_pre(c_a, ap, res);
	if (c_a->spec == 'p')
		go_print_p_pre(c_a, ap, res);
	if (c_a->spec == 'n')
		go_proc_n(ap, res);
	if (c_a->spec == 'b')
		go_print_b(c_a, ap, res);
	if (!isspec(c_a->spec))
		(c_a->flag[2] == '-' ? go_print_cm : go_print_c)(c_a, c_a->spec, res);
}

size_t	fillstruct(const char *format, t_arg *cur_arg, va_list ap, int *res)
{
	char	*str;
	size_t	i;
	int		pro;

	i = 1;
	while (!nonspecc(*(format + i)) && !isspec(*(format + i)))
		i++;
	str = ft_strsub(format, 0, i + 1);
	fill_w_p(str, cur_arg, ap);
	fillflag(str, cur_arg);
	i = 0;
	while (str[i])
	{
		pro = (i == 0) ? 1 : 0;
		if (isspec(str[i + pro]) || nonspecc(str[i + pro]))
			cur_arg->spec = str[i];
		if (islenth(str[i]))
			i = i + filllenth(str[i], str[i + 1], cur_arg->lenth);
		i++;
	}
	free(str);
	go_print(cur_arg, ap, res);
	return (i);
}

int		check_colour(int *res, const char **s)
{
	if (!(ft_strncmp(*s, "{red}", 5)) && (*s += 5))
		*res += write(1, RED, 5);
	else if (!(ft_strncmp(*s, "{green}", 7)) && (*s += 7))
		*res += write(1, GREEN, 5);
	else if (!(ft_strncmp(*s, "{yellow}", 8)) && (*s += 8))
		*res += write(1, YELLOW, 5);
	else if (!(ft_strncmp(*s, "{blue}", 6)) && (*s += 6))
		*res += write(1, BLUE, 5);
	else if (!(ft_strncmp(*s, "{magenta}", 9)) && (*s += 9))
		*res += write(1, MAGENTA, 5);
	else if (!(ft_strncmp(*s, "{cyan}", 6)) && (*s += 6))
		*res += write(1, CYAN, 5);
	else if (!(ft_strncmp(*s, "{white}", 7)) && (*s += 7))
		*res += write(1, WHITE, 5);
	else if (!(ft_strncmp(*s, "{eoc}", 5)) && (*s += 5))
		*res += write(1, EOC, 4);
	else
		return (0);
	return (1);
}

int		ft_printf(const	char *format, ...)
{
	va_list	ap;
	t_arg	cur_arg;
	int		result;

	result = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
		{
			if (*format == '{')
			{
				if (!check_colour(&result, &format))
					result += write(1, format++, 1);
				continue ;
			}
			result += write(1, format++, 1);
		}
		if (*format == '%')
		{
			set_struct(&cur_arg);
			format = format + fillstruct(format, &cur_arg, ap, &result);
		}
	}
	return (result);
}
