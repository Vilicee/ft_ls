/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:36:13 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/02 14:27:32 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_organize_args(t_input_data *data, t_args *input)
{
	data->d = 0;
	data->e = 0;
	data->f = 0;
	if (input->errors > 1)
		ft_organize_errors(data, input);
	if (input->valid_files > 1)
		ft_organize_files(data, input);
	if (input->valid_directories > 1)
		ft_organize_dirs(data, input);
}
