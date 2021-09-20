/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adhoc_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:39:36 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:18:28 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_adhoc_atoi(const char *str, t_printf *data)
{
	int	res;

	res = 0;
	while (str[data->i] >= 48 && str[data->i] <= 57)
	{
		res = (res * 10) + str[data->i] - 48;
		data->i++;
		data->waste++;
	}
	return (res);
}
