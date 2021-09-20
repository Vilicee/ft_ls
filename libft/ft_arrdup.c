/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:50:55 by wvaara            #+#    #+#             */
/*   Updated: 2021/08/30 13:24:28 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	**ft_arrdup(char **array)
{
	char		**copy;
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (array[len])
		len++;
	copy = (char **)malloc(sizeof(char *) * (len + 1));
	if (copy)
	{
		while (array[i])
		{
			copy[i] = ft_strdup(array[i]);
			i++;
		}
		copy[i] = NULL;
	}
	return (copy);
}
