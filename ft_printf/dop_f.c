/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:39:40 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/04 22:56:46 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

char	*joinf(char *str, char *str2)
{
	char *concat;

	concat = ft_strjoin(str, str2);
	free(str);
	free(str2);
	return (concat);
}

char	*intoa(intmax_t n)
{
	intmax_t	num;
	char		*str;
	int			i;

	num = n;
	i = 0;
	if (n < 0)
		i = 1;
	while ((n > 9 || n < -9) && ++i)
		n /= 10;
	if (!(str = ft_strnew(i + 1)))
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (str[i] != '-' && i >= 0)
	{
		str[i--] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}

void	capitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			str[i] -= 32;
		i++;
	}
}

char	nonspecc(char c)
{
	char	*str;

	str = "sSpdDioOuUxXcC #+-0hljz123456789.*";
	if (ft_strchr(str, c))
		return (0);
	return (c);
}
