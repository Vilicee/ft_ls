/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:34:18 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/19 17:37:35 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static int	ft_parse_options(t_args *input, char *argv, int i)
{
	while (argv[i] != '\0')
	{
		if (argv[i] == 'R')
			input->R = '1';
		else if (argv[i] == 'r')
			input->r = '1';
		else if (argv[i] == 'l')
			input->l = '1';
		else if (argv[i] == 'a')
			input->a = '1';
		else if (argv[i] == 't')
			input->t = '1';
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", argv[i]);
			ft_printf("usage: ./ft_ls [-Rralt] [file ...]\n");
			return (-1);
		}
		input->options = '1';
		i++;
	}
	input->dash++;
	return (0);
}

int	ft_parse_args(t_args *input, char *argv)
{
	if (argv[0] == '-')
	{
		if (input->valid_flag != '1' && input->check_dash != '1')
		{
			if (ft_parse_options(input, argv, 1) == -1)
				return (-1);
		}
		else
			input->errors++;
	}
	else
		input->errors++;
	return (0);
}
