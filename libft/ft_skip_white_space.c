/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_white_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:15:57 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/02 17:25:07 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	ft_count_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_skip_white_space(char *str)
{
	int		i;
	int		len;
	int		start;
	char	*temp;

	i = 0;
	len = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == 9)
		i++;
	start = i;
	len = ft_count_len(str, i);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp)
	{
		i = 0;
		while (str[start])
		{
			temp[i] = str[start];
			i++;
			start++;
		}
		temp[i] = '\0';
	}
	return (temp);
}
