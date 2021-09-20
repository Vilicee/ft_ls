/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:49:54 by wvaara            #+#    #+#             */
/*   Updated: 2021/08/27 18:15:37 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>

void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putstr(array[i]);
		write(1, "\n", 1);
		i++;
	}
}
