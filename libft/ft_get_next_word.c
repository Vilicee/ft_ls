/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:51:18 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/02 12:49:54 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	ft_word_len(char *str, int i)
{
	int	start;

	start = i;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '"' || str[i] == '\'' || str[i] == '`'
			|| str[i] == ' ')
			break ;
		i++;
	}
	return (i - start);
}

char	*ft_get_next_word(char *str, int i)
{
	int		len;
	int		ii;
	char	*ret;

	ii = 0;
	len = ft_word_len(str, i);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret)
	{
		while (len > 0)
		{
			ret[ii++] = str[i++];
			len--;
		}
		ret[ii] = '\0';
	}
	return (ret);
}
