/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reserve_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:05:30 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/19 17:38:02 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int	ft_reserve_memory(t_args *input, t_input_data *data)
{
	if (input->valid_directories > 0)
	{
		data->dirs = (char **)malloc(sizeof(char *)
				* (input->valid_directories + 1));
		if (!data->dirs)
			return (-1);
	}
	if (input->valid_files > 0)
	{
		data->fil = (char **)malloc(sizeof(char *)
				* (input->valid_files + 1));
		if (!data->fil)
			return (-1);
	}
	if (input->errors > 0)
	{
		data->err = (char **)malloc(sizeof(char *) * (input->errors + 1));
		if (!data->err)
			return (-1);
	}
	input->i = 0;
	if (input->options == '1' || input->check_dash == '1')
		return (input->dash + 1);
	return (1);
}
