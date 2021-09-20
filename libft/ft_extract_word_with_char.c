/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_word_with_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:30:51 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/13 10:32:07 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	ft_word_len(char *str, int i, char end)
{
	int	start;

	start = i;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '"' || str[i] == '\'' || str[i] == '`'
			|| str[i] == ' ' || str[i] == end)
			break ;
		i++;
	}
	return (i - start);
}

char	*ft_extract_word_with_char(char *str, int i, char end)
{
	int		len;
	int		ii;
	char	*ret;

	ii = 0;
	len = ft_word_len(str, i, end);
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
