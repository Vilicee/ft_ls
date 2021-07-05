/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:18:29 by wvaara            #+#    #+#             */
/*   Updated: 2021/06/15 12:18:17 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_ascii_order(t_no_flags *data)
{
	char	*temp;

	data->i = 0;
	while (data->i < data->files - 1)
	{
		if (ft_strcmp(data->entry[data->i], data->entry[data->i + 1]) > 0)
		{
			temp = data->entry[data->i];
			data->entry[data->i] = data->entry[data->i + 1];
			data->entry[data->i + 1] = temp;
			if (data->i >= 2)
				data->i = data->i - 2;
			else
				data->i = 0;
		}
		else
			data->i++;
	}
}
