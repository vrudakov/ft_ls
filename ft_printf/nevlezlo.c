/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nevlezlo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:40:10 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/05 17:43:40 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			isspec(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "sSpdDioOuUxXcCn";
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int			islenth(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

static char	*reverse_num(char *res)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen(res);
	temp = ft_strnew(len--);
	while (len >= 0)
	{
		temp[i++] = res[len];
		len--;
	}
	temp[i] = '\0';
	free(res);
	return (temp);
}

char		*itoa_base(unsigned long long int num, int base)
{
	char					*res;
	int						i;
	unsigned long long int	temp;

	i = 0;
	if (num == 0)
		return (ft_strdup("0"));
	res = ft_strnew(21);
	while (num != 0)
	{
		temp = num % base;
		res[i++] = (temp < 10) ? (char)(temp + 48) : (char)(temp - 10 + 97);
		num = num / base;
	}
	res = reverse_num(res);
	return (res);
}
