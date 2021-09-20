/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:28:45 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/07 15:34:32 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_arrlen(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	if (array)
	{
		while (array[i])
			i++;
	}
	return (i);
}
