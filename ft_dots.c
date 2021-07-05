/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dots.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:00:11 by wvaara            #+#    #+#             */
/*   Updated: 2021/06/11 17:52:02 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int	ft_dots(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		while (str[i] != '\0')
		{
			if (str[i] != '.')
				return (0);
			i++;
		}
		if (i == 1 || i == 2)
			return (-1);
	}
	return (0);
}
