/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:14:33 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/04 22:38:21 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	go_print_u(t_arg *cur_arg, char *d, int *res, unsigned long long int di)
{
	char	*pstr;

	if (di == 0 && cur_arg->precision == 0 && cur_arg->wd != 0)
		ft_memset(d, ' ', cur_arg->wd);
	if (di == 0 && cur_arg->precision == 0 && cur_arg->wd == 0)
		return ;
	if (ft_strlen(d) > cur_arg->wd)
		cur_arg->wd = (int)ft_strlen(d);
	pstr = ft_strnew(cur_arg->wd - ft_strlen(d));
	if (cur_arg->flag[1] == '0')
		ft_memset(pstr, '0', cur_arg->wd - ft_strlen(d));
	else
		ft_memset(pstr, ' ', cur_arg->wd - ft_strlen(d));
	pstr = joinf(pstr, d);
	*res += ft_strlen(pstr);
	ft_putstr(pstr);
	free(pstr);
}

void	go_print_um(t_arg *cur_arg, char *d, int *re, unsigned long long int di)
{
	char *pstr;

	if (di == 0 && cur_arg->precision == 0)
	{
		free(d);
		d = ft_strnew(cur_arg->wd);
		ft_memset(d, ' ', cur_arg->wd);
	}
	if (ft_strlen(d) > cur_arg->wd)
		cur_arg->wd = (int)ft_strlen(d);
	pstr = ft_strnew((size_t)cur_arg->wd);
	ft_memset((pstr), ' ', (size_t)cur_arg->wd);
	ft_memcpy(pstr, d, ft_strlen(d));
	*re += write(1, pstr, ft_strlen(pstr));
	free(d);
	free(pstr);
}

char	*go_print_u_pre_two(t_arg *cur_arg, unsigned long long int dg)
{
	char *frmd;
	char *d;

	d = itoa_base(dg, 10);
	if (ft_strlen(d) < cur_arg->precision && cur_arg->precision != -1)
	{
		frmd = ft_strnew((size_t)cur_arg->precision - ft_strlen(d));
		ft_memset(frmd, '0', cur_arg->precision - ft_strlen(d));
		frmd = joinf(frmd, d);
		return (frmd);
	}
	return (d);
}

void	go_print_u_pre(t_arg *cur_arg, va_list ap, int *res)
{
	unsigned long long int	d;
	char					*sd;

	d = va_arg(ap, unsigned long long int);
	if (cur_arg->lenth[5] == 'z')
		d = (size_t)d;
	else if (cur_arg->lenth[4] == 'j')
		d = (uintmax_t)d;
	else if (cur_arg->lenth[3] == 'L' || cur_arg->spec == 'U')
		d = (unsigned long long int)d;
	else if (cur_arg->lenth[2] == 'l')
		d = (unsigned long int)d;
	else if (cur_arg->lenth[1] == 'h')
		d = (unsigned short int)d;
	else if (cur_arg->lenth[0] == 'H')
		d = (unsigned char)d;
	else
		d = (unsigned int)d;
	sd = go_print_u_pre_two(cur_arg, d);
	if (cur_arg->precision != -1)
		cur_arg->flag[1] = '\0';
	(cur_arg->flag[2] == '-' ? go_print_um : go_print_u)(cur_arg, sd, res, d);
}
