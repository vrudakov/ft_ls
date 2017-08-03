/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:34:00 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/14 19:22:16 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*fresh;

	if (s)
	{
		i = 0;
		fresh = ft_strnew(ft_strlen(s));
		fresh = ft_strdup(s);
		if (fresh)
		{
			while (fresh[i])
			{
				fresh[i] = f(s[i]);
				i++;
			}
			fresh[i] = '\0';
			return (fresh);
		}
		return (NULL);
	}
	return (NULL);
}
