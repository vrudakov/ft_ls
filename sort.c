/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:16:06 by vrudakov          #+#    #+#             */
/*   Updated: 2017/04/23 17:16:14 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	order(t_list *elem, t_list *next)
{
	t_item *item;

	if (elem->content == NULL || next->content == NULL)
		return ;
	if (ft_strcmp(((t_item*)elem->content)->i_name,
				((t_item*)next->content)->i_name) > 0)
	{
		item = elem->content;
		elem->content = next->content;
		next->content = item;
	}
}

static void	time_order(t_list *elem, t_list *next)
{
	t_item *item;

	if (elem->content == NULL || next->content == NULL)
		return ;
	if (((t_item*)elem->content)->stat.st_mtimespec.tv_sec <=
			((t_item*)next->content)->stat.st_mtimespec.tv_sec)
	{
		if (((t_item*)elem->content)->stat.st_mtimespec.tv_sec ==
				((t_item*)next->content)->stat.st_mtimespec.tv_sec)
			if (((t_item*)elem->content)->stat.st_mtimespec.tv_nsec >
					((t_item*)next->content)->stat.st_mtimespec.tv_nsec)
				return ;
		item = elem->content;
		elem->content = next->content;
		next->content = item;
	}
}

static void	reverse(t_list **head_ref)
{
	t_list *prev;
	t_list *current;
	t_list *next;

	current = *head_ref;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void		ft_lstsort(t_list *lst, void (*f)(t_list *elem, t_list *elem2))
{
	t_list	*temp;
	t_list	*second;

	if (lst == NULL || lst->next == NULL)
		return ;
	temp = lst;
	second = lst->next;
	while (temp)
	{
		while (second)
		{
			f(temp, second);
			second = second->next;
		}
		temp = temp->next;
		second = temp;
	}
}

t_list		*sort_list(t_list *begin)
{
	if (begin != NULL)
	{
		if (g_flag[FLAG_F] == 'f')
		{
			if (g_flag[FLAG_R] != 'r')
				reverse(&begin);
			return (begin);
		}
		if (g_flag[FLAG_T] == 't')
			ft_lstsort(begin, time_order);
		else
			ft_lstsort(begin, order);
		if (g_flag[FLAG_R] != '\0')
			reverse(&begin);
	}
	return (begin);
}
