/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:44:05 by vrudakov          #+#    #+#             */
/*   Updated: 2016/11/22 19:44:08 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t n)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (dest[c] != '\0')
		c++;
	while (src[i] != '\0' && n > 0)
	{
		dest[c] = src[i];
		i++;
		c++;
		n--;
	}
	dest[c] = '\0';
	return (dest);
}
