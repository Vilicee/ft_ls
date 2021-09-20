/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:15:34 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 14:10:43 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putlonglong_fd(long long int n, int fd)
{
	char	res;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
		ft_putlonglong_fd(n * 0.1, fd);
	res = n % 10 + 48;
	write(fd, &res, 1);
}
