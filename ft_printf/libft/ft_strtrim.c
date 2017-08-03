/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:37:07 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/14 17:53:48 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*fresh;
	size_t	i2;
	size_t	j;

	i = 0;
	i2 = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t') || s[i] == '\0')
	{
		if (s[i] == '\0')
			return (ft_strdup(""));
		i++;
	}
	while ((s[j - 1] == ' ') || (s[j - 1] == '\n') || (s[j - 1] == '\t'))
	{
		j--;
		i2++;
	}
	fresh = ft_strsub(s, i, ft_strlen(s) - i2 - i);
	return (fresh);
}
