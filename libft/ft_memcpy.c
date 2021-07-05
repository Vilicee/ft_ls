/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 09:31:50 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:00:38 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*srce;
	unsigned char	*dest;

	srce = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	if (dst && src)
	{
		while (n > 0 && srce[i] != '\0' && dest[i] != '\0')
		{
			dest[i] = srce[i];
			i++;
			n--;
		}
	}
	return (dst);
}
