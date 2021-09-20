/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:42:50 by wvaara            #+#    #+#             */
/*   Updated: 2021/08/05 19:02:00 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub != NULL)
	{
		while (str[start] != '\0' && len > 0)
		{
			sub[i] = str[start];
			start++;
			i++;
			len--;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
