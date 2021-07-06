/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:24:14 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/06 15:46:32 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;
	size_t	ii;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	ii = ft_strlen(s2);
	fresh = (char *)malloc(sizeof(char) * (i + ii + 1));
	if (!fresh)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		fresh[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		fresh[i] = *s2;
		i++;
		s2++;
	}
	fresh[i] = '\0';
	return (fresh);
}
