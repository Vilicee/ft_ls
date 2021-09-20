/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_negative.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:31:57 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:18:56 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_for_negative(t_printf *data)
{
	data->neg = 0;
	data->save_neg = 0;
	if (data->hn < 0)
		data->neg = 1;
	if (data->hhn < 0)
		data->neg = 1;
	if (data->uhn < 0)
		data->neg = 1;
	if (data->uhhn < 0)
		data->neg = 1;
	if (data->lln < 0)
		data->neg = 1;
	if (data->uln < 0)
		data->neg = 1;
	if (data->ulln < 0)
		data->neg = 1;
	if (data->n < 0)
		data->neg = 1;
	if (data->un < 0)
		data->neg = 1;
	if (data->neg == 1)
		data->save_neg = 1;
}
