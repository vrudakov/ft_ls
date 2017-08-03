/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 16:58:34 by vrudakov          #+#    #+#             */
/*   Updated: 2017/04/23 16:58:36 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_listsize(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	freesher(t_list *mfree, int i)
{
	t_list	*tmp;
	t_item	*tmp_item;

	while (mfree)
	{
		if (i == 0)
			tmp = mfree->next;
		tmp_item = mfree->content;
		if (tmp_item == NULL)
			break ;
		ft_strdel(&tmp_item->i_name);
		if (tmp_item->path != NULL)
			ft_strdel(&tmp_item->path);
		free(tmp_item);
		free(mfree);
		mfree = NULL;
		if (i == 0)
			mfree = tmp;
		if (i == 1)
			break ;
	}
}
