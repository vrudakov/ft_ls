/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:47:01 by vrudakov          #+#    #+#             */
/*   Updated: 2016/11/25 18:47:06 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*in;
	unsigned char	*out;

	in = (unsigned char*)src;
	out = (unsigned char*)dst;
	while (n > 0)
	{
		if ((*out++ = *in++) == (unsigned char)c)
			return ((void*)out);
		n--;
	}
	return (NULL);
}
