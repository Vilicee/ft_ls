/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:49:56 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:01:20 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

static void	ft_puthexa(size_t n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthexa(n / 16);
		ft_puthexa(n % 16);
	}
	else
		write(1, &base[n], 1);
}

void	ft_putaddr(void **ptr)
{
	write(1, "0x", 2);
	ft_puthexa((size_t)ptr);
}
