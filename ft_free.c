/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:20:31 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/02 17:34:07 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_free(t_no_flags *data)
{
	int	i;

	i = 0;
	while (i <= data->files)
	{
		free(data->entry[i]);
		i++;
	}
	free(data->entry);
}
