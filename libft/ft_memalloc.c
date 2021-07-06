/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:09:51 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/06 15:43:52 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (size > 2147483647 || size < 0)
		return (NULL);
	str = malloc(sizeof(void) * (size + 1));
	if (!str)
		return (NULL);
	if (size > 0)
	{
		ft_bzero(str, size);
		return (str);
	}
	return (NULL);
}
