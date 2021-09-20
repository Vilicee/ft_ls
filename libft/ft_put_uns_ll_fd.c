/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_ll_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:01:09 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 12:02:29 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_uns_ll_fd(unsigned long long n, int fd)
{
	char	res;

	if (n >= 10)
		ft_put_uns_ll_fd(n / 10, fd);
	res = n % 10 + 48;
	write(fd, &res, 1);
}
