/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:10:28 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/13 16:33:44 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_organize_errors(t_input_data *data, t_args *input)
{
	char	*temp;
	
	while (data->e < input->errors - 1)
	{
		if (ft_strcmp(data->err[data->e], data->err[data->e + 1]) > 0)
		{
			temp = data->err[data->e + 1];
			data->err[data->e + 1] = data->err[data->e];
			data->err[data->e] = temp;
			data->e = 0;
		}
		else
			data->e++;
	}
}
