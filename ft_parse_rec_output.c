/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rec_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:28:25 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/14 17:30:51 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int	ft_parse_rec_output(t_args *input, char *latter, char *former, char *temp)
{
	if (input->argc == 0)
		ft_printf("ft_ls: %s: Permission denied\n", latter);
	if (input->file == '1' && input->l == '0')
		ft_printf("ft_ls: %s: Permission denied\n", former);
	if (latter)
		free(temp);
	return (-1);
}
