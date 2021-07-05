/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:06:53 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:16:57 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_wordcount(const char *str, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i - 1] != c && i != 0)
			count++;
		i++;
		if (str[i] == '\0' && str[i - 1] != c)
			count++;
	}
	return (count);
}
