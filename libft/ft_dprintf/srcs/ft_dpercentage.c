/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpercentage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:44:35 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 13:46:30 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_perc(t_data *data)
{
	if (data->minus == 1)
		write(data->fd, "%", 1);
	while (data->xtra > 1)
	{
		if (data->zero == '1' && data->minus == 0)
			write(data->fd, "0", 1);
		else
			write(data->fd, " ", 1);
		data->ret++;
		data->xtra--;
	}
	if (data->minus == 0)
		write(data->fd, "%", 1);
	data->minus = 0;
}

void	ft_dpercentage(t_data *data)
{
	if (data->save == 1)
		ft_perc(data);
	else
		write(data->fd, "%", 1);
	data->waste++;
	data->ret++;
}
