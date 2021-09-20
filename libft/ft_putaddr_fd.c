/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:08:25 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 12:09:51 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

static void	ft_puthexa(size_t n, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthexa(n / 16, fd);
		ft_puthexa(n % 16, fd);
	}
	else
		write(fd, &base[n], 1);
}

void	ft_putaddr_fd(void **ptr, int fd)
{
	write(fd, "0x", 2);
	ft_puthexa((size_t)ptr, fd);
}
