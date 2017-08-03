/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:01:16 by vrudakov          #+#    #+#             */
/*   Updated: 2017/04/23 17:02:06 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_ls.h"
# include "libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <memory.h>
# include <sys/time.h>
# include <pwd.h>
# include <grp.h>
# include "ft_printf/ft_printf.h"

# define FLAG_L			0
# define FLAG_RB		1
# define FLAG_A			2
# define FLAG_R			3
# define FLAG_T			4
# define FLAG_AT		5
# define FLAG_G			6
# define FLAG_TB        7
# define FLAG_F			8
# define MANY			9
# define TIME			stat.st_mtimespec.tv_sec

char			g_flag[10];

typedef struct		s_item
{
	struct stat		stat;
	char			*path;
	char			*i_name;
	char			type;
}					t_item;

typedef struct		s_max
{
	int				max_link;
	int				max_user;
	int				max_grp;
	int				max_size;
}					t_max;

t_max				*g_max;
void				item_info(t_list *list);
/*
** sort
*/
void				t_lstsort(t_list *lst, void (*f)(t_list *elem,
													t_list *elem2));
t_list				*sort_list(t_list *begin);

/*
** dop
*/

int					many_list(t_list *list);
int					ft_listsize(t_list *list);
void				freesher(t_list *mfree, int i);

/*
** perms
*/
char				*lsperms(int mode);
int					filetypeletter(int mode);
void				flag_error(char flg);
int					check_flags(char *str);

t_item				*create_item(char *i_name, char *c_dir);
t_list				*all_items(char *dir);

void				total(t_list *list);
char				*xattr(char *path);
void				write_time(t_item *item);
char				*l_info(t_item *item);

void				init_max(void);
void				fill_max(t_item *item);
void				check_link(t_item *item);
void				item_info(t_list *list);

#endif
