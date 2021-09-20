/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_last_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:11:12 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/07 15:23:56 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_remove_last_word(char *str, char c)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != c && i > 0)
		i--;
	if (i == 0)
		return (ft_strdup("/"));
	temp = (char *)malloc(sizeof(char) * (i + 2));
	temp[i] = '\0';
	if (i != 0)
		i--;
	if (temp)
	{
		while (i >= 0)
		{
			temp[i] = str[i];
			i--;
		}
	}
	return (temp);
}
