/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:47:33 by wvaara            #+#    #+#             */
/*   Updated: 2021/02/17 12:23:08 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				ret;
	int				i;
	unsigned char	*ptr;
	unsigned char	*ptr1;

	ret = 0;
	i = 0;
	if (!s1 || !s2)
		return (-1);
	ptr = (unsigned char *)s1;
	ptr1 = (unsigned char *)s2;
	while (n > 0)
	{
		if (ptr[i] != ptr1[i])
			return (ptr[i] - ptr1[i]);
		i++;
		n--;
	}
	return (ret);
}
