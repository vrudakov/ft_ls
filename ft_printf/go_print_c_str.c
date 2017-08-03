/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print_c_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 23:23:33 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/05 17:44:13 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	go_print_str(t_arg *cur_arg, char *str, int *res)
{
	int		i;
	size_t	len;
	char	*ret;

	len = ft_strlen(str);
	if (ft_strlen(str) > cur_arg->wd && cur_arg->precision != 0)
		cur_arg->wd = (int)len;
	if (cur_arg->precision < len)
		len = (size_t)cur_arg->precision;
	ret = ft_strnew((size_t)cur_arg->wd);
	if (cur_arg->flag[1] == '0')
		ft_memset(ret, '0', (size_t)cur_arg->wd);
	else
		ft_memset(ret, ' ', (size_t)cur_arg->wd);
	i = -1;
	while (len > ++i)
		ret[i + (ft_strlen(ret) - len)] = str[i];
	i = 0;
	*res += ft_strlen(ret);
	while (cur_arg->wd > i)
		ft_putchar(ret[i++]);
	free(str);
	free(ret);
}

void	go_print_strm(t_arg *cur_arg, char *str, int *res)
{
	char	*ret;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (ft_strlen(str) > cur_arg->wd)
		cur_arg->wd = (int)len;
	if (cur_arg->precision < len)
		len = (size_t)cur_arg->precision;
	ret = ft_strnew((size_t)cur_arg->wd);
	ft_memset(ret, ' ', (size_t)cur_arg->wd);
	while (len > i)
	{
		ret[i] = str[i];
		i++;
	}
	i = 0;
	*res += ft_strlen(ret);
	while (cur_arg->wd > i)
		ft_putchar(ret[i++]);
	free(str);
	free(ret);
}

void	go_print_str_pre(t_arg *cur_arg, va_list ap, int *res)
{
	char	*arg;
	int		len;
	char	*str;
	int		f;

	f = 0;
	arg = va_arg(ap, char*);
	if (arg == NULL)
	{
		f = 1;
		arg = ft_strdup("(null)");
	}
	len = (int)ft_strlen(arg);
	if (cur_arg->precision != -1)
		len = cur_arg->precision;
	str = ft_strnew((size_t)len);
	while (--len >= 0)
		str[len] = arg[len];
	if (cur_arg->flag[2] == '-')
		go_print_strm(cur_arg, str, res);
	if (cur_arg->flag[2] != '-')
		go_print_str(cur_arg, str, res);
	if (f == 1)
		free(arg);
}
