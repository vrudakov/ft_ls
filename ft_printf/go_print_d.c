/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:03:29 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/05 17:40:23 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void		go_print_d(t_arg *c_a, char *d, int *res, intmax_t di)
{
	char	*pstr;
	int		sign;

	sign = (c_a->flag[3] == '+' || c_a->flag[4] == 's' || (di < 0)) ? 1 : 0;
	if (di == 0 && c_a->precision == 0 && c_a->wd != 0)
		ft_memset(d, ' ', c_a->wd);
	if (di == 0 && c_a->precision == 0 && c_a->wd == 0)
		return ;
	c_a->wd = (ft_strlen(d) > c_a->wd) ? ft_strlen(d) + sign : c_a->wd;
	pstr = ft_strnew(c_a->wd - ft_strlen(d));
	if (c_a->flag[1] == '0')
		ft_memset(pstr, '0', c_a->wd - ft_strlen(d));
	else
		ft_memset(pstr, ' ', c_a->wd - ft_strlen(d));
	if (c_a->flag[4] == 's')
		pstr[0] = ' ';
	if ((c_a->flag[3] == '+' || (di < 0)) && c_a->flag[1] == '0')
		pstr[0] = (char)((di < 0) ? '-' : '+');
	else if ((c_a->flag[3] == '+' || (di < 0)) && c_a->precision == -1)
		pstr[c_a->wd - ft_strlen(d) - 1] = (char)((di < 0) ? '-' : '+');
	else if ((c_a->flag[3] == '+' || (di < 0)) && c_a->precision != -1)
		pstr[ft_strlen(pstr) - 1] = (char)((di < 0) ? '-' : '+');
	*res += write(1, pstr, ft_strlen(pstr)) + write(1, d, ft_strlen(d));
	free(d);
	free(pstr);
}

void		go_print_dm(t_arg *ca, char *d, int *res, intmax_t di)
{
	char	*pstr;
	int		sgn;

	sgn = 0;
	if (di == 0 && ca->precision == 0)
	{
		free(d);
		d = ft_strnew(ca->wd);
		ft_memset(d, ' ', ca->wd);
	}
	if (ft_strlen(d) > ca->wd)
		ca->wd = (int)ft_strlen(d);
	pstr = ft_strnew((size_t)ca->wd);
	if (((ca->flag[3] == '+' && (ca->wd = ca->wd - 1)) || di < 0) && (sgn += 1))
		pstr[0] = (char)(di < 0 ? '-' : '+');
	if (ca->flag[4] == 's' && (ca->wd = ca->wd - 1) && (sgn += 1))
		pstr[0] = ' ';
	if (di < 0)
		ft_memset((pstr + sgn), ' ', (size_t)ca->wd - sgn);
	else
		ft_memset((pstr + sgn), ' ', (size_t)ca->wd);
	ft_memcpy(pstr + sgn, d, ft_strlen(d));
	*res += write(1, pstr, ft_strlen(pstr));
	free(d);
	free(pstr);
}

char		*go_print_d_pre_two(t_arg *cur_arg, intmax_t dg)
{
	char *frmd;
	char *d;

	if (dg == LLONG_MIN)
		d = ft_strdup("9223372036854775808");
	else
		d = (dg < 0) ? intoa(-dg) : intoa(dg);
	if (ft_strlen(d) < cur_arg->precision && cur_arg->precision != -1)
	{
		frmd = ft_strnew((size_t)cur_arg->precision - ft_strlen(d));
		ft_memset(frmd, '0', cur_arg->precision - ft_strlen(d));
		frmd = joinf(frmd, d);
		return (frmd);
	}
	return (d);
}

void		go_print_d_pre(t_arg *cur_arg, va_list ap, int *res)
{
	intmax_t	d;
	char		*sd;

	d = va_arg(ap, intmax_t);
	if (cur_arg->lenth[5] == 'z')
		d = (size_t)d;
	else if (cur_arg->lenth[4] == 'j')
		d = (intmax_t)d;
	else if (cur_arg->lenth[3] == 'L')
		d = (long long int)d;
	else if (cur_arg->lenth[2] == 'l' || cur_arg->spec == 'D')
		d = (long int)d;
	else if (cur_arg->lenth[1] == 'h')
		d = (short int)d;
	else if (cur_arg->lenth[0] == 'H')
		d = (signed char)d;
	else
		d = (int)d;
	sd = go_print_d_pre_two(cur_arg, d);
	if (cur_arg->precision != -1)
		cur_arg->flag[1] = '\0';
	if (cur_arg->flag[3] == '+')
		cur_arg->flag[4] = '\0';
	(cur_arg->flag[2] == '-' ? go_print_dm : go_print_d)(cur_arg, sd, res, d);
}
