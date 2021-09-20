/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:43:11 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/06 18:29:35 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int	ft_skip(char const *str, int i)
{
	while (ft_isspace(str[i]) == 1)
		i++;
	return (i);
}

char	*ft_strtrim(char const *str)
{
	char	*sub;
	int		len;
	int		i;
	int		ii;
	int		end;

	i = ft_skip(str, 0);
	if (str[i] == '\0')
		return (ft_strdup(""));
	end = i;
	while (str[end] != '\0')
		end++;
	while (ft_isspace(str[end - 1]) == 1)
		end--;
	if (end == 0)
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(char) * (end - i + 1));
	if (!sub)
		return (NULL);
	ii = end - i;
	len = ii;
	while (end >= i)
		sub[ii--] = str[end--];
	sub[len] = '\0';
	return (sub);
}
