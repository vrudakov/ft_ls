/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:24:52 by vrudakov          #+#    #+#             */
/*   Updated: 2016/12/02 21:25:06 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long tmp;
	long num;

	tmp = n;
	if (n < 0)
	{
		tmp = -tmp;
		write(fd, "-", 1);
	}
	if (tmp >= 10)
		ft_putnbr_fd(tmp / 10, fd);
	num = tmp % 10 + 48;
	write(fd, &num, 1);
}
