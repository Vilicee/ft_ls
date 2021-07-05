/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 13:25:24 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:13:59 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strnlen(const char *str, size_t len)
{
	int	i;
	int	ret;

	i = 0;
	if (!str)
		return (NULL);
	ret = ft_strlen(str);
	if (ret > len)
	{
		while (len > 0)
		{
			if (str[i] == '\0')
				return (i + len);
			len--;
			i++;
		}
		return (len);
	}
	return (ret);
}
