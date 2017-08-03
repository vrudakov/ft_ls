/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:36:28 by vrudakov          #+#    #+#             */
/*   Updated: 2017/04/30 21:10:01 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	g_flag[10];

void	rec(t_list *list)
{
	t_item	*temp;
	t_list	*now;
	t_list	*allitems;

	if (g_flag[FLAG_L])
		total(list);
	ft_lstiter(list, &item_info);
	write(1, "\n", 1);
	while (list)
	{
		temp = list->content;
		if (temp->type == 'd' && ft_strcmp(temp->i_name, "..") &&
			ft_strcmp(temp->i_name, "."))
		{
			write(1, temp->path, ft_strlen(temp->path));
			write(1, ":\n", 2);
			allitems = all_items(temp->path);
			rec(allitems);
		}
		now = list->next;
		freesher(list, 1);
		list = now;
	}
}

void	main_proc(t_list *list)
{
	t_item			*in;
	t_list			*l_list;

	l_list = NULL;
	in = list->content;
	if (in->type == 'd')
	{
		l_list = all_items(in->path);
		if (g_flag[MANY] == 'm')
			ft_printf("%s:\n", in->path);
		if (g_flag[FLAG_RB != '\0'])
		{
			rec(l_list);
			return ;
		}
	}
	else
		item_info(list);
	if (g_flag[FLAG_L] == 'l' && in->type == 'd')
		total(l_list);
	ft_lstiter(l_list, &item_info);
	write(1, "\n", 1);
	freesher(l_list, 0);
}

void	dir_l_printall(t_list *list, int type)
{
	t_list			*now;
	t_item			*tmp;

	while (list)
	{
		tmp = list->content;
		if (tmp && type == 0 && tmp->type == 'f')
			main_proc(list);
		if (tmp && type == 1 && tmp->type == 'd')
			main_proc(list);
		now = list->next;
		if (tmp && type != 0)
			freesher(list, 1);
		list = now;
	}
}

t_list	*collect_arg(int argc, char **argv)
{
	int		i;
	t_list	*list;
	t_item	*new;

	i = 1;
	list = NULL;
	while (i < argc && argv[i][0] == '-')
	{
		check_flags(argv[i++]);
	}
	if (i == argc)
		return (all_items("."));
	while (i < argc)
	{
		new = create_item(argv[i], "");
		ft_lstadd(&list, ft_lstnew(new, sizeof(t_item)));
		free(new);
		i++;
	}
	if (ft_listsize(list) > 1)
		g_flag[MANY] = 'm';
	list = sort_list(list);
	dir_l_printall(list, 0);
	dir_l_printall(list, 1);
	exit(EXIT_SUCCESS);
}

int		main(int argc, char **argv)
{
	t_list		*list;

	init_max();
	list = collect_arg(argc, argv);
	if (g_flag[FLAG_RB != '\0'])
	{
		rec(list);
	}
	else
		ft_lstiter(list, &item_info);
	return (0);
}
