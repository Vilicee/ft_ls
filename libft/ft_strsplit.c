/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:50:47 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/04 19:44:10 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	**ft_strsplit(char const *str, char c)
{
	char	**fresh;
	size_t	words;
	size_t	wlen;
	size_t	i;

	i = 0;
	words = ft_wordcount(str, c);
	fresh = (char **)malloc(sizeof(char *) * (words + 1));
	if (!fresh)
		return (NULL);
	while (words > 0)
	{
		while (*str == c)
			str++;
		if (*str != c)
		{
			wlen = ft_wordlength(str, c);
			fresh[i] = ft_strsub(str, 0, wlen);
			i++;
			str = str + wlen;
		}
		words--;
	}
	fresh[i] = NULL;
	return (fresh);
}
