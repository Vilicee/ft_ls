/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:30:04 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:13:26 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	if (ft_strlen(src) + 1 >= len)
	{
		while (src[i] != '\0' && len-- > 0)
			*(dst++) = src[i++];
		*dst = '\0';
		return (&*(dst = dst - i));
	}
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	len = len - i;
	while (len > 0)
	{
		dst[i] = '\0';
		len--;
		i++;
	}
	return (dst);
}
