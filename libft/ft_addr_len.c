/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:04:20 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 11:49:27 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "includes/libft.h"

static int	ft_count_len(size_t nbr)
{
	int	ret;

	ret = 0;
	while (nbr > 16)
	{
		nbr = nbr / 16;
		ret++;
	}
	ret++;
	return (ret);
}

int	ft_addr_len(void **ptr)
{
	int	ret;

	ret = 0;
	ret = ft_count_len((size_t)ptr);
	ret = ret + 2;
	return (ret);
}
