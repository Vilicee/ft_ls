/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:35:11 by wvaara            #+#    #+#             */
/*   Updated: 2021/08/05 19:57:02 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strcdup(const char *src, char c)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		if (src[len] != c)
			dest[i++] = src[len];
		len++;
	}
	dest[i] = '\0';
	return (dest);
}
