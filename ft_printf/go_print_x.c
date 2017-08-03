/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:16:12 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/04 22:16:18 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	go_print_x(t_arg *cur_arg, char *d, int *res)
{
	char *pd;

	if ((int)ft_strlen(d) > cur_arg->wd)
	{
		*res += write(1, d, ft_strlen(d));
		free(d);
		return ;
	}
	pd = ft_strnew((size_t)cur_arg->wd);
	if (cur_arg->flag[1] == '0')
	{
		ft_memset(pd, '0', (size_t)cur_arg->wd - (int)ft_strlen(d));
		if (cur_arg->flag[0] == '#')
		{
			pd[1] = (char)((cur_arg->spec == 'x') ? 'x' : 'X');
			d[1] = '0';
		}
	}
	else
		ft_memset(pd, ' ', (size_t)cur_arg->wd - (int)ft_strlen(d));
	*res = (int)(*res + write(1, pd, ft_strlen(pd)) +
		write(1, d, ft_strlen(d)));
	free(d);
	free(pd);
}

void	go_print_xm(t_arg *cur_arg, char *d, int *res)
{
	int		len;
	char	*pd;

	len = (int)ft_strlen(d);
	if (cur_arg->wd > len)
	{
		pd = ft_strnew((size_t)cur_arg->wd);
		ft_memset(pd, ' ', (size_t)cur_arg->wd);
		pd = ft_memmove(pd, d, (size_t)len);
		ft_putstr(pd);
		*res += ft_strlen(pd);
		free(pd);
	}
	else
		*res += write(1, d, ft_strlen(d));
	free(d);
}

char	*go_print_x_pre_two(t_arg *cur_arg, unsigned long long int dg)
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
	if (cur_arg->flag[0] == '#' && dg != 0)
		d = joinf(sharp, d);
	else
		free(sharp);
	return (d);
}

void	go_print_x_pre(t_arg *cur_arg, va_list ap, int *res)
{
	unsigned long long int	d;
	char					*sd;

	d = va_arg(ap, unsigned long long int);
	if (cur_arg->lenth[5] == 'z')
		d = (size_t)d;
	else if (cur_arg->lenth[4] == 'j')
		d = (uintmax_t)d;
	else if (cur_arg->lenth[3] == 'L')
		d = (unsigned long long int)d;
	else if (cur_arg->lenth[2] == 'l')
		d = (unsigned long int)d;
	else if (cur_arg->lenth[1] == 'h')
		d = (unsigned short int)d;
	else if (cur_arg->lenth[0] == 'H')
		d = (unsigned char)d;
	else
		d = (unsigned int)d;
	sd = go_print_x_pre_two(cur_arg, d);
	if (d == 0 && cur_arg->precision == 0)
		sd[0] = '\0';
	if (cur_arg->precision != -1)
		cur_arg->flag[1] = '\0';
	(cur_arg->flag[2] == '-' ? go_print_xm : go_print_x)(cur_arg, sd, res);
}
