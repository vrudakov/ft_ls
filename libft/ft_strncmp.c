/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:50:40 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/14 20:55:56 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t num)
{
	unsigned char a;
	unsigned char b;

	a = *first;
	b = *second;
	if (num == 0)
		return (0);
	while (a == b && num > 0)
	{
		a = *first++;
		b = *second++;
		if (a == '\0')
		{
			return ((int)a - b);
		}
		num--;
	}
	return ((int)a - b);
}
