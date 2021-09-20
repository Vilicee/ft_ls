/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drounding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:26:59 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 13:43:09 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_part_one(t_data *data)
{
	while (data->deci[data->check++] != '\0')
	{
		if (data->deci[data->check] > '0')
		{
			data->check = -1;
			break ;
		}	
	}
	if (data->check == -1)
	{
		if (data->deci[data->ii] == '9')
		{
			data->deci[data->ii] = '0';
			data->next = '1';
		}
		else
			data->deci[data->ii] = data->deci[data->ii] + 1;
	}	
}

static int	ft_part_two(t_data *data)
{
	if (data->cap_l == 1)
	{
		if (data->deci[data->ii] == '0' && data->check != -1
			&& data->precision == 1)
		{
			data->deci[data->ii] = data->deci[data->ii] + 1;
			return (-1);
		}
		if (data->deci[data->ii] == '3' && data->check != -1
			&& data->precision == 1)
			return (-1);
		if (data->precision == 1 && data->deci[data->ii] == '8'
			&& data->check != -1)
		{
			data->deci[data->ii] = data->deci[data->ii] + 1;
			return (-1);
		}
		if (data->precision == 1 && data->check != -1
			&& data->deci[data->ii] == '9')
			return (-1);
	}
	return (0);
}

static void	ft_part_three(t_data *data)
{
	if (data->deci[data->ii + 1] == '5' && data->check != -1)
	{	
		if (data->deci[data->ii] == '1' || data->deci[data->ii] == '3'
			|| data->deci[data->ii] == '5' || data->deci[data->ii] == '7')
			data->deci[data->ii] = data->deci[data->ii] + 1;
		if (data->deci[data->ii] == '9')
		{
			data->deci[data->ii] = '0';
			data->next = '1';
		}
	}
	if (data->deci[data->ii + 1] > '5')
	{
		if (data->deci[data->ii] == '9')
		{
			data->deci[data->ii] = '0';
			data->next = '1';
		}
		else
			data->deci[data->ii] = data->deci[data->ii] + 1;
	}
}

static void	ft_part_four(t_data *data)
{
	while (data->next == '1' && data->ii > 0)
	{
		if (data->deci[data->ii - 1] == '9')
			data->deci[data->ii - 1] = '0';
		else
		{
			data->deci[data->ii - 1] = data->deci[data->ii - 1] + 1;
			data->next = '0';
		}
		data->ii--;
	}
	if (data->next == '1')
		data->roundup = '1';
	if (data->precision == 0 && data->deci[0] == '5')
	{
		if (data->int_part % 2 != 0)
			data->roundup = '1';
	}
	if (data->precision == 0 && data->deci[0] > '5')
		data->roundup = '1';
}

void	ft_drounding(t_data *data)
{
	data->prec = data->precision;
	if (data->prec == 0)
		data->prec = 1;
	data->ii = data->prec - 1;
	data->check = data->ii + 1;
	if (data->cap_l == 1)
		ft_dcap_l_round(data);
	if (data->deci[data->ii + 1] == '5')
	{
		ft_part_one(data);
		if (ft_part_two(data) == -1)
			return ;
	}
	ft_part_three(data);
	ft_part_four(data);
}
