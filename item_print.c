/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:11:35 by vrudakov          #+#    #+#             */
/*   Updated: 2017/04/23 17:11:38 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	total(t_list *list)
{
	t_item		*tmp;
	int			total;

	total = 0;
	while (list)
	{
		tmp = list->content;
		if (g_flag[FLAG_A] != 'a' && tmp->i_name[0] == '.')
		{
			list = list->next;
			continue ;
		}
		total += tmp->stat.st_blocks;
		list = list->next;
	}
	if (total != 0)
	{
		write(1, "total ", 6);
		ft_putnbr(total);
	}
	write(1, "\n", 1);
}

char	*xattr(char *path)
{
	ssize_t	buflen;
	char	*buf;

	buflen = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (buflen == 0)
	{
		return (0);
	}
	buf = malloc((size_t)buflen);
	buflen = listxattr(path, buf, (size_t)buflen, XATTR_NOFOLLOW);
	return (buf);
}

void	write_time(t_item *item)
{
	if (g_flag[FLAG_TB] == 'T')
	{
		ft_printf(" %.20s ", ctime(&item->TIME) + 4);
		return ;
	}
	if ((time(NULL) - item->TIME) > 15724800 || item->TIME > time(NULL))
		ft_printf(" %.7s %.4s ", ctime(&item->TIME) + 4,
				ctime(&item->TIME) + 20);
	else
		ft_printf(" %.12s ", ctime(&item->TIME) + 4);
}

char	*l_info(t_item *item)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*attr;

	ft_printf("%s", lsperms(item->stat.st_mode));
	if ((attr = xattr(item->path)) > 0)
		ft_printf("@ %*d ", g_max->max_link - 1, item->stat.st_nlink);
	else
		ft_printf(" %*d ", g_max->max_link, item->stat.st_nlink);
	pwd = getpwuid(item->stat.st_uid);
	if (pwd == NULL)
		perror("getpwuid");
	else if (g_flag[FLAG_G] != 'g')
		ft_printf("%*-s", g_max->max_user, pwd->pw_name);
	if ((grp = getgrgid(item->stat.st_gid)) != NULL)
		ft_printf(" %*-s", g_max->max_grp + 1, grp->gr_name);
	else
		ft_printf(" %-8d", item->stat.st_gid);
	ft_printf("%*lld", g_max->max_size + 2, item->stat.st_size);
	write_time(item);
	return (attr);
}
