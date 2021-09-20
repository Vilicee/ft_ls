/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dcheck_for_negative.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:31:57 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/17 17:16:51 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void	ft_dcheck_for_negative(t_data *data)
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
