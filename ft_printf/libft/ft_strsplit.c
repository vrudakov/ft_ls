/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:44:41 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/02 09:45:18 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *st, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (st[i] != '\0')
	{
		if (st[i] == c)
			i++;
		else
		{
			while (st[i] != c && st[i] != '\0')
				i++;
			j++;
		}
	}
	return (j);
}

static char	*ft_write(char const *s, int *i, char c)
{
	char	*out;
	int		count;
	int		w;

	w = 0;
	count = *i;
	while (s[count] != c && s[*i])
	{
		count++;
	}
	out = (char*)malloc(sizeof(char) * (count + 1));
	while (s[*i] != c && s[*i])
	{
		out[w] = s[*i];
		w++;
		*i += 1;
	}
	out[w] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (out);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		m;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	m = ft_count(s, c);
	ret = (char**)malloc(sizeof(s) * (m + 1));
	if (!ret)
		return (NULL);
	while (s[i] != '\0' && j < m)
	{
		if (s[i] == c)
			i++;
		else
		{
			ret[j] = ft_write(s, &i, c);
			j++;
		}
	}
	ret[j] = NULL;
	return (ret);
}
