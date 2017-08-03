/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:11:07 by vrudakov          #+#    #+#             */
/*   Updated: 2017/04/23 17:11:09 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_item		*create_item(char *i_name, char *c_dir)
{
	t_item		*item;
	char		*tmp_path;
	char		*add;

	add = "/";
	item = (t_item*)malloc(sizeof(t_item));
	if (ft_strlen(c_dir) != 0 && c_dir[(int)ft_strlen(c_dir) - 1] != '/')
		tmp_path = ft_strjoin(c_dir, add);
	else
		tmp_path = ft_strdup(c_dir);
	item->path = ft_strjoin(tmp_path, i_name);
	item->i_name = ft_strdup(i_name);
	if (lstat(item->path, &item->stat) < 0)
	{
		perror(i_name);
		free(tmp_path);
		free(item->path);
		free(item->i_name);
		free(item);
		return (NULL);
	}
	item->type = (char)((S_ISDIR(item->stat.st_mode)) ? 'd' : 'f');
	fill_max(item);
	free(tmp_path);
	return (item);
}

t_list		*all_items(char *dir)
{
	t_list			*list;
	DIR				*dr;
	struct dirent	*dirn;
	t_item			*new;

	list = NULL;
	dr = opendir(dir);
	if (dr == NULL)
	{
		perror("ft_ls");
		return (NULL);
	}
	while ((dirn = readdir(dr)) != NULL)
	{
		if (dirn->d_name[0] == '.' && g_flag[FLAG_A] != 'a')
			continue ;
		new = create_item(dirn->d_name, dir);
		ft_lstadd(&list, ft_lstnew(new, sizeof(t_item)));
		free(new);
	}
	closedir(dr);
	list = sort_list(list);
	return (list);
}
