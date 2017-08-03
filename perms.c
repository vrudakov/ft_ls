/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:35:30 by vrudakov          #+#    #+#             */
/*   Updated: 2017/03/27 20:35:32 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*lsperms(int mode)
{
	static const char	*rwx[] = {"---", "--x", "-w-", "-wx",
							"r--", "r-x", "rw-", "rwx"};
	static char			bits[11];

	bits[0] = filetypeletter(mode);
	ft_strcpy(&bits[1], rwx[(mode >> 6) & 7]);
	ft_strcpy(&bits[4], rwx[(mode >> 3) & 7]);
	ft_strcpy(&bits[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		bits[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		bits[6] = (mode & S_IXGRP) ? 's' : 'l';
	if (mode & S_ISVTX)
		bits[9] = (mode & S_IXOTH) ? 't' : 'T';
	bits[10] = '\0';
	return (bits);
}

int			filetypeletter(int mode)
{
	char	c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return (c);
}

void		flag_error(char flg)
{
	write(1, "ft_ls: illegal option -- ", 25);
	write(1, &flg, 1);
	write(1, "\nusage: ft_ls [-lRart@gTf] [file ...]\n", 34);
	exit(1);
}

void		check_flags_pt_two(char str)
{
	char *etalon;

	etalon = "-lRart@gTf";
	if (str == 'g')
	{
		g_flag[FLAG_G] = 'g';
		g_flag[FLAG_L] = 'l';
	}
	if (str == 'T')
		g_flag[FLAG_TB] = 'T';
	if (str == 'f')
	{
		g_flag[FLAG_F] = 'f';
		g_flag[FLAG_A] = 'a';
	}
}

int			check_flags(char *str)
{
	char *etalon;

	etalon = "-lRart@gTf";
	while (*str)
	{
		if (!ft_strchr(etalon, *str))
			flag_error(*str);
		if (*str == 'l')
			g_flag[FLAG_L] = 'l';
		if (*str == 'R')
			g_flag[FLAG_RB] = 'R';
		if (*str == 'a')
			g_flag[FLAG_A] = 'a';
		if (*str == 'r')
			g_flag[FLAG_R] = 'r';
		if (*str == 't')
			g_flag[FLAG_T] = 't';
		if (*str == '@')
			g_flag[FLAG_AT] = '@';
		check_flags_pt_two(*str);
		str++;
	}
	return (0);
}
