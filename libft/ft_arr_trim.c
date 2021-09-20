/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:47:06 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/01 19:10:07 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	**ft_arr_trim(char **array)
{
	int		i;
	char	**temp;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * (ft_arrlen(array) + 1));
	if (temp)
	{
		while (array[i])
		{
			temp[i] = ft_get_next_word(array[i], 0);
			i++;
		}
		temp[i] = NULL;
	}
	return (temp);
}
