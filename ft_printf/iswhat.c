/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iswhat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 21:49:28 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/04 22:10:22 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

void	set_struct(t_arg *cur_arg)
{
	cur_arg->flag[0] = '\0';
	cur_arg->flag[1] = '\0';
	cur_arg->flag[2] = '\0';
	cur_arg->flag[3] = '\0';
	cur_arg->flag[4] = '\0';
	cur_arg->lenth[0] = '\0';
	cur_arg->lenth[1] = '\0';
	cur_arg->lenth[2] = '\0';
	cur_arg->lenth[3] = '\0';
	cur_arg->lenth[4] = '\0';
	cur_arg->lenth[5] = '\0';
	cur_arg->spec = '\0';
	cur_arg->wd = 0;
	cur_arg->precision = -1;
}

void	fillflag(char *str, t_arg *cur_arg)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			cur_arg->flag[0] = '#';
		if (str[i] == '0' && !ft_isdigit(str[i - 1]))
			cur_arg->flag[1] = '0';
		if (str[i] == '-')
			cur_arg->flag[2] = '-';
		if (str[i] == '+')
			cur_arg->flag[3] = '+';
		if (str[i] == ' ')
			cur_arg->flag[4] = 's';
		i++;
	}
}

int		filllenth(char a, char b, char *str)
{
	if (a == 'h' && b == 'h')
		return ((str[0] = 'H') ? 1 : 1);
	if (a == 'h' && b != 'h')
		return ((str[1] = a) ? 0 : 0);
	if (a == 'l' && b != 'l')
		return ((str[2] = a) ? 0 : 0);
	if (a == 'l' && b == 'l')
		return ((str[3] = 'L') ? 1 : 1);
	if (a == 'j')
		return ((str[4] = a) ? 0 : 0);
	if (a == 'z')
		return ((str[5] = a) ? 0 : 0);
	return (0);
}

int		fill_p(char *str, t_arg *cur_arr, va_list ap)
{
	int c;
	int d;

	c = 0;
	if (ft_isdigit(*(str + 1)) || *(str + 1) == 42)
	{
		if (*(str + 1) == '*')
		{
			d = va_arg(ap, int);
			cur_arr->precision = (d < 0) ? cur_arr->precision : d;
			return (2);
		}
		while (ft_isdigit(*(str + 1 + c)))
			c++;
		cur_arr->precision = ft_atoi(str + 1);
	}
	else
		cur_arr->precision = 0;
	return (c);
}

void	fill_w_p(char *str, t_arg *cur_arr, va_list ap)
{
	size_t			c;

	c = 0;
	while (*str)
	{
		if (ft_isdigit(*str) && *str != '0')
		{
			while (ft_isdigit(*(str + c)))
				c++;
			cur_arr->wd = (ft_atoi(str) == 0) ? 1 : (ft_atoi(str));
			str = str + c;
			c = 0;
		}
		if (*str == '.')
			str = str + fill_p(str, cur_arr, ap);
		if (*str == 42 && (cur_arr->wd = va_arg(ap, unsigned int)))
		{
			if (cur_arr->wd < 0)
			{
				cur_arr->flag[2] = '-';
				cur_arr->wd *= -1;
			}
		}
		str++;
	}
}
