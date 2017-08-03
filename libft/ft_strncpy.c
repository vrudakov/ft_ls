/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:16:14 by vrudakov          #+#    #+#             */
/*   Updated: 2016/11/22 16:16:18 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while (str2[i] != '\0' && i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	while (i < n)
	{
		str1[i] = '\0';
		i++;
	}
	return (str1);
}
