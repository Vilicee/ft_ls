/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:01:12 by wvaara            #+#    #+#             */
/*   Updated: 2021/03/04 12:27:28 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	if (!dst || !src)
		return (-1);
	if (len > 0)
	{
		while (src[i] != '\0' && len > 1)
		{
			dst[i] = src[i];
			i++;
			len--;
		}
		dst[i] = '\0';
		ret = ft_strlen(src);
		return (ret);
	}
	if (len <= 0)
		ret = ft_strlen(src);
	return (ret);
}
