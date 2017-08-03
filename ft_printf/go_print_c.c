/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:42:56 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/04 22:42:51 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	go_print_char(t_arg *cur_arg, va_list ap, int *res)
{
	if (cur_arg->flag[2] == '-')
		go_print_cm(cur_arg, (char)va_arg(ap, int), res);
	else
		go_print_c(cur_arg, (char)va_arg(ap, int), res);
}

void	go_print_c(t_arg *cur_arg, char x, int *res)
{
	char	*str;
	int		i;

	i = 0;
	if (cur_arg->wd == 0)
		cur_arg->wd = 1;
	str = ft_strnew((size_t)cur_arg->wd);
	if (cur_arg->flag[1] == '0')
		ft_memset(str, '0', (size_t)cur_arg->wd);
	else
		ft_memset(str, ' ', (size_t)cur_arg->wd);
	str[cur_arg->wd - 1] = x;
	*res += cur_arg->wd;
	while (cur_arg->wd > i)
		ft_putchar(str[i++]);
	free(str);
}

void	go_print_cm(t_arg *cur_arg, char x, int *res)
{
	char	*str;
	int		i;

	i = 0;
	if (cur_arg->wd == 0)
		cur_arg->wd = 1;
	str = ft_strnew((size_t)cur_arg->wd);
	if (cur_arg->flag[2] == '-')
	{
		ft_memset(str, ' ', (size_t)cur_arg->wd);
		str[0] = x;
		*res += cur_arg->wd;
		while (cur_arg->wd > i)
			ft_putchar(str[i++]);
		free(str);
		return ;
	}
	free(str);
}
