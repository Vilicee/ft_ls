/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:21:38 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:03:54 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	if (!str)
		return (NULL);
	ptr = ((char *)str);
	while (*str != '\0')
	{
		if (*str == c)
			return (ptr);
		if (c == '\0' && *(str + 1) == '\0')
		{
			ptr++;
			return (ptr);
		}
		str++;
		ptr++;
	}
	if (*str == '\0' && c == '\0')
		return (ptr);
	return (NULL);
}
