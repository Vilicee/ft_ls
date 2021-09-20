/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 11:44:48 by wvaara            #+#    #+#             */
/*   Updated: 2021/08/16 12:40:32 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*ptr;
	int			ret;

	ret = 0;
	if (!haystack || !needle)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			ret = ft_strlen(needle);
			if (ft_strncmp(haystack, needle, ret) == 0)
			{
				ptr = haystack;
				return ((char *)ptr);
			}
		}
		haystack++;
	}
	return (NULL);
}
