/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 23:01:27 by vrudakov          #+#    #+#             */
/*   Updated: 2016/11/26 23:01:35 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*in;
	char	*out;

	in = (char*)src;
	out = (char*)dst;
	if (len == 0)
		return (out);
	if (out != in)
	{
		if (out < in)
			return (ft_memcpy(out, in, len));
		if (out > in)
			return (ft_memcpy_rev(out, in, len));
	}
	return (out);
}
