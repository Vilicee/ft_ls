/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:20:15 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/07 15:10:32 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int	ft_word_len(char *str, int i, char c)
{
	int	start;

	start = i;
	while (str[i])
	{
		if (str[i] == c || str[i] == '\n' || str[i] == '\0')
			break ;
		i++;
	}
	return (i - start);
}

char	*ft_extract_word(char *str, int i, char c)
{
	int		len;
	int		ii;
	char	*ret;

	ii = 0;
	len = ft_word_len(str, i, c);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret)
	{
		while (len > 0)
		{
			ret[ii++] = str[i++];
			len--;
		}
	}
	ret[ii] = '\0';
	return (ret);
}
