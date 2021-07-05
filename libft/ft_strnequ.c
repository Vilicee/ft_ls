/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:31:37 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:13:39 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t len)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (len > 0)
	{
		if (s1[i] != '\0' || s2[i] != '\0')
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
		len--;
	}
	return (1);
}
