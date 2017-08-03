/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print_p_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:47:08 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/04 22:30:14 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*go_print_p_pre_two(t_arg *cur_arg, unsigned long long int dg)
{
	char	*d;
	char	*sharp;
	char	*zero;
	int		len;

	sharp = (cur_arg->spec == 'x') ? ft_strdup("0x") : ft_strdup("0X");
	d = itoa_base(dg, 16);
	if (cur_arg->spec == 'X')
		capitalize(d);
	len = (int)ft_strlen(d);
	if (cur_arg->precision > len)
	{
		zero = ft_strnew((size_t)(cur_arg->precision - len));
		ft_memset(zero, '0', (size_t)(cur_arg->precision - len));
		d = joinf(zero, d);
	}
	d = joinf(sharp, d);
	return (d);
}

void	go_print_p_pre(t_arg *cur_arg, va_list ap, int *res)
{
	unsigned long long	d;
	char				*sd;

	d = va_arg(ap, long int);
	cur_arg->flag[0] = '#';
	cur_arg->spec = 'x';
	sd = go_print_p_pre_two(cur_arg, d);
	if (d == 0 && cur_arg->precision == 0)
	{
		*res += write(1, "0x", 2);
		return ;
	}
	if (cur_arg->precision != -1)
		cur_arg->flag[1] = '\0';
	(cur_arg->flag[2] == '-' ? go_print_xm : go_print_x)(cur_arg, sd, res);
}

void	go_proc_n(va_list ap, int *res)
{
	int		*now_res;

	now_res = va_arg(ap, int*);
	*now_res = *res;
}

void	go_print_b(t_arg *cur_arg, va_list ap, int *res)
{
	char	*b;
	int		d;

	d = va_arg(ap, int);
	b = itoa_base(d, 2);
	if (cur_arg->flag[2] == '-')
		go_print_dm(cur_arg, b, res, d);
	else
		go_print_d(cur_arg, b, res, d);
}
