/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_entries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:00:06 by wvaara            #+#    #+#             */
/*   Updated: 2021/06/22 17:12:13 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_print_entries(t_args *input, t_no_flags *data)
{
	if (ft_save_entries(data, input, ".") == -1)
		return ;
	if (input->t == '1')
		ft_order_by_time(data, input, ".");
	else
		ft_ascii_order(data);
	ft_print_list(data, input, ".");
	ft_free(data);
}
