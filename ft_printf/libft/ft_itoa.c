/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:48:30 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/02 11:20:06 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_dop(char *st, int num, int amount, int sign)
{
	st[amount] = '\0';
	amount--;
	while (amount >= 0)
	{
		st[amount] = (char)((num % 10) + '0');
		num = num / 10;
		amount--;
	}
	if (sign == 1)
	{
		st[0] = '-';
	}
	return (st);
}

static int	ft_capacity(int cap)
{
	int		amt;

	amt = 0;
	while (cap != 0)
	{
		cap = cap / 10;
		amt++;
	}
	return (amt);
}

char		*ft_itoa(int n)
{
	int		amt;
	char	*out;
	int		sign;

	amt = ft_capacity(n);
	sign = 0;
	if (n == -2147483648)
		return (out = ft_strdup("-2147483648"));
	if (n == 0)
		return (out = ft_strdup("0"));
	if (n < 0)
	{
		sign += 1;
		n = -n;
	}
	amt += sign;
	out = (char*)malloc(sizeof(char) * (amt + 1));
	if (!out)
		return (NULL);
	out = ft_dop(out, n, amt, sign);
	return (out);
}
