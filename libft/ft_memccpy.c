/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:00:04 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 11:59:50 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*srce;
	unsigned char	*dest;

	srce = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	if (!dst || !src)
		return (NULL);
	while (n > 0)
	{
		dest[i] = srce[i];
		if (srce[i] == (unsigned char)c)
		{
			return (dest + i + 1);
		}
		i++;
		n--;
	}
	return (NULL);
}
