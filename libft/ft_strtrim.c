/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:43:11 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:16:02 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strtrim(char const *str)
{
	char	*sub;
	int		len;
	int		i;
	int		ii;
	int		end;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	end = i;
	while (str[end] != '\0')
		end++;
	while (str[end - 1] == ' ' || str[end - 1] == '\n' || str[end - 1] == '\t')
		end--;
	if (end == 0)
		return (sub = ft_strdup(""));
	sub = (char *)malloc(sizeof(*sub) * (end - i + 1));
	if (!sub)
		return (NULL);
	ii = end - i;
	len = ii;
	while (end >= i)
		sub[ii--] = str[end--];
	sub[len] = '\0';
	return (sub);
}
