/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcap_l_round.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:50:28 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:16:58 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void	ft_dcap_l_round(t_data *data)
{
	if (data->deci[data->ii + 1] == '4')
	{
		data->check = data->ii + 2;
		while (data->deci[data->check++] != '\0')
		{
			if (data->deci[data->check] != '9')
			{
				if (data->deci[data->check] <= '5')
					data->check = -1;
				if (data->deci[data->check] > '5')
					data->check = 0;
				break ;
			}
		}
		if (data->check > -1)
		{
			data->check = data->ii + 2;
			while (data->deci[data->check] != '\0')
				data->deci[data->check++] = '0';
			data->deci[data->ii + 1] = data->deci[data->ii + 1] + 1;
		}
	}
	data->check = data->ii + 1;
}
