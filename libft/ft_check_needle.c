/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_needle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:33:47 by wvaara            #+#    #+#             */
/*   Updated: 2021/08/16 12:02:49 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_check_needle(const char *haystack, const char *needle)
{
	int	ret;

	ret = 0;
	if (!haystack || !needle)
		return (-1);
	if (*needle == '\0')
		return (-1);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			ret = ft_strlen(needle);
			if (ft_strncmp(haystack, needle, ret) == 0)
				return (1);
		}
		haystack++;
	}
	return (0);
}
