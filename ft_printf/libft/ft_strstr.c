/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:22:28 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/14 18:06:43 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
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
				return ((char*)(&big[i]));
			if (big[i + c] == '\0')
				return (0);
			c++;
		}
		i++;
	}
	return (0);
}
