/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:11:08 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/14 20:47:19 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char	const *s, unsigned int start, size_t len)
{
	char				*fresh;
	unsigned int		i;

	i = 0;
	fresh = (char*)malloc(sizeof(char) * len + 1);
	if (!fresh || !s)
		return (NULL);
	while (len)
	{
		fresh[i++] = s[start++];
		len--;
	}
	fresh[i] = '\0';
	return (fresh);
}
