/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:08:07 by vrudakov          #+#    #+#             */
/*   Updated: 2016/11/26 16:08:10 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	char	*in;
	char	*out;

	in = (char*)src;
	out = (char*)dst;
	if (n == 0 || dst == src)
		return (in);
	while (n--)
		out[n] = in[n];
	return (out);
}
