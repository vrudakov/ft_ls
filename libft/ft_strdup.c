/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:29:12 by vrudakov          #+#    #+#             */
/*   Updated: 2016/11/23 13:43:44 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dup;

	dup = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	dup = ft_strcpy(dup, s1);
	return (dup);
}
