/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serve_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:14:13 by vrudakov          #+#    #+#             */
/*   Updated: 2017/04/23 17:14:15 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_max(void)
{
	g_max = (t_max*)malloc(sizeof(t_max));
	g_max->max_grp = 1;
	g_max->max_link = 3;
	g_max->max_size = 1;
	g_max->max_user = 1;
}

int		num_len(long long num)
{
	int t;

	t = 0;
	while (num)
	{
		num = num / 10;
		t++;
	}
	return (t);
}

void	fill_max(t_item *item)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(item->stat.st_uid);
	if (num_len(item->stat.st_nlink) > g_max->max_link)
		g_max->max_link = num_len(item->stat.st_nlink);
	if (ft_strlen(pwd->pw_name) > (size_t)g_max->max_user)
		g_max->max_user = (int)ft_strlen(pwd->pw_name);
	grp = getgrgid(item->stat.st_gid);
	if (ft_strlen(grp->gr_name) > (size_t)g_max->max_grp)
		g_max->max_grp = (int)ft_strlen(grp->gr_name);
	if (num_len(item->stat.st_size) > g_max->max_size)
		g_max->max_size = num_len(item->stat.st_size);
}

void	check_link(t_item *item)
{
	char	buf[1024];

	ft_memset(buf, '\0', 1024);
	if (lsperms(item->stat.st_mode)[0] == 'l' && g_flag[FLAG_L] != '\0')
	{
		readlink(item->path, buf, 1024);
		ft_printf(" -> %s \n", buf);
	}
	else
		write(1, "\n", 1);
}

void	item_info(t_list *list)
{
	t_item			*item;
	char			*attr;

	item = list->content;
	attr = ft_strnew(1);
	if (lstat(item->path, &item->stat) < 0)
	{
		perror("");
		return ;
	}
	if (item->i_name[0] == '.' && g_flag[FLAG_A] != 'a')
		return ;
	if (g_flag[FLAG_L] != '\0')
	{
		free(attr);
		attr = l_info(item);
	}
	ft_printf("%s", item->i_name);
	check_link(item);
	if (attr > 0 && g_flag[FLAG_L] != '\0' && g_flag[FLAG_AT] != '\0')
	{
		ft_printf("         %s", attr);
		ft_printf("     %d\n", getxattr(item->path, attr, NULL, 0, 0, 0x0001));
	}
	free(attr);
}
