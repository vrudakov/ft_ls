/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:23:05 by vrudakov          #+#    #+#             */
/*   Updated: 2016/11/30 17:23:08 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		len;
	int		i;
	int		c;

	i = 0;
	c = 0;
	len = 0;
	if (!s1 || !s2)
		return (NULL);
	fresh = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!fresh)
		return (NULL);
	while (s1[i])
	{
		fresh[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		fresh[i + c] = s2[c];
		c++;
	}
	fresh[i + c] = '\0';
	return (fresh);
}
