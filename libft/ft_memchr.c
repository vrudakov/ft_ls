/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 22:13:41 by vrudakov          #+#    #+#             */
/*   Updated: 2016/11/26 22:13:42 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	f;
	size_t	i;
	char	*str;

	i = 0;
	f = (char)c;
	str = (char*)s;
	while (n > 0)
	{
		if (f == str[i])
			return ((char*)(s + i));
		i++;
		n--;
	}
	return (NULL);
}
