/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:35:24 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/05 15:37:01 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*list;
	t_list	*alist;

	if (lst == NULL && (*f) == NULL)
		return (NULL);
	head = NULL;
	while (lst != NULL)
	{
		alist = (*f)(lst);
		if (head == NULL)
		{
			head = ft_lstnew(alist->content, alist->content_size);
			list = head;
		}
		else
		{
			list->next = ft_lstnew(alist->content, alist->content_size);
			list = list->next;
		}
		if (!list)
			break ;
		lst = lst->next;
	}
	return (head);
}
