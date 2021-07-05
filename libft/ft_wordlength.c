/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlength.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 08:48:07 by wvaara            #+#    #+#             */
/*   Updated: 2021/04/21 12:17:11 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_wordlength(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}
