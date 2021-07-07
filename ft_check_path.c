/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:25:58 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/07 12:42:47 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int	ft_check_path(char *ptr, char *argv)
{
	char	slash;
	int		i;
	
	i = 0;
	slash = '0';
	if (ft_find_char(ptr, '/') == 1)
		slash = '1';
	if (ft_find_char(argv, '/') == 1)
	{
		if (slash == '1')
			slash = '2';
		else
			slash = '3';
	}
	if (slash == '1')
		return (0);
	if (slash == '2')
		return (0);
	if (slash == '3')
		return (-1);
	return (0);
}
