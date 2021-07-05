/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelength.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 08:48:07 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 11:57:38 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_linelength(const char *str, char c)
{
	size_t	count;

	count = 0;
	if (!str)
		return (-1);
	if (*str != c)
	{
		while (*str != c && *str)
		{
			str++;
			count++;
		}
		return (count);
	}
	if (*str == c)
		count++;
	return (count);
}
