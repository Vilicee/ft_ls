/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 09:49:49 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:00:01 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*strptr;

	if (!str)
		return (NULL);
	strptr = (unsigned char *)str;
	while (n > 0 && *strptr != '\0')
	{
		if (*strptr == (unsigned char)c)
			return ((void *)strptr);
		strptr++;
		n--;
	}
	return (NULL);
}
