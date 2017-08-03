/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:47:48 by vrudakov          #+#    #+#             */
/*   Updated: 2017/02/26 17:36:05 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*in;
	char	*out;

	in = (char*)src;
	out = (char*)dst;
	while (n > 0)
	{
		*out++ = *in++;
		n--;
	}
	return (dst);
}
