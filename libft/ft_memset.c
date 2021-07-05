/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:38:12 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/17 12:50:17 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int		i;
	char	*ptr;

	if (!str)
		return (NULL);
	ptr = str;
	i = 0;
	while (len > 0)
	{
		ptr[i] = c;
		i++;
		len--;
	}
	return (str);
}
