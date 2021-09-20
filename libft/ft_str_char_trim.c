/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char_trim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:04:30 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/06 19:10:55 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	ft_str_len(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			i++;
			count++;
		}
	}
	return (count);
}

char	*ft_str_char_trim(char *str, char c)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
	len = ft_str_len(str, c);
	temp = (char *)malloc(sizeof(char *) * (len + 1));
	if (temp)
	{
		len = 0;
		while (str[i])
		{
			if (str[i] == c)
				i++;
			else
				temp[len++] = str[i++];
		}
		temp[len] = '\0';
	}
	return (temp);
}
