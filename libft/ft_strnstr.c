/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:41:15 by vrudakov          #+#    #+#             */
/*   Updated: 2016/11/24 13:41:17 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int c;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		c = 0;
		while (big[i + c] == little[c])
		{
			if (little[c + 1] == '\0')
			{
				if (i + c + 1 > (int)len)
					return (NULL);
				else
					return ((char*)(&big[i]));
			}
			if (big[i + c] == '\0')
				return (NULL);
			c++;
		}
		i++;
	}
	return (NULL);
}
