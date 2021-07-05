/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:29:43 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:12:11 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*map;
	int		ret;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	ret = ft_strlen(str);
	map = (char *)malloc(sizeof(*map) * (ret + 1));
	if (!map)
		return (NULL);
	while (str[i] != '\0')
	{
		map[i] = f(str[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
