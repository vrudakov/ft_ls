/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print_str_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:16:46 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/04 22:16:51 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

size_t		ft_wlen(wchar_t *wstr)
{
	size_t	i;

	i = 0;
	while (wstr[i] != L'\0')
	{
		i++;
	}
	return (i);
}

void		go_print_str_pre_s(t_arg *cur_arg, va_list ap, int *res)
{
	wchar_t	*arg;
	int		len;
	char	*str;
	int		f;
	int		i;

	i = 0;
	f = 0;
	arg = va_arg(ap, wchar_t*);
	if (arg == NULL && (f = 1))
	{
		*res += write(1, "(null)", 6);
		return ;
	}
	len = (int)ft_wlen(arg);
	if (cur_arg->precision != -1)
		len = cur_arg->precision;
	str = ft_strnew((size_t)len);
	while (*arg)
		str[i++] = (char)*arg++;
	(cur_arg->flag[2] == '-' ? go_print_strm : go_print_str)(cur_arg, str, res);
	if (f == 1)
		free(arg - i);
}
