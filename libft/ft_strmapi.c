/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:40:45 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/14 19:22:52 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	if (s)
	{
		i = 0;
		fresh = ft_strnew(ft_strlen(s));
		fresh = ft_strdup(s);
		if (fresh)
		{
			while (fresh[i])
			{
				fresh[i] = f(i, s[i]);
				i++;
			}
			fresh[i] = '\0';
			return (fresh);
		}
		return (NULL);
	}
	return (NULL);
}
