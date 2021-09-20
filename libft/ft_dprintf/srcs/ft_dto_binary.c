/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dto_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:01:05 by wvaara            #+#    #+#             */
/*   Updated: 2021/09/10 13:40:51 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static void	ft_part_two(t_data *data, char *base_two, int i)
{
	while (data->n > 0)
	{
		data->n = data->n * 10;
		data->n = data->n * 0.5;
		if (data->n % 10 == 0)
			base_two[i] = '0';
		else
			base_two[i] = '1';
		i--;
		data->n = data->n * 0.1;
	}
	if (data->base == 8)
	{
		while (i > 0)
			base_two[i--] = '0';
		i = 1;
	}
	else
		i = 0;
}

static int	ft_check_size(t_data *data)
{
	int	size;

	size = 0;
	if (data->id == 0)
		size = 32;
	if (data->id == 1)
		size = 8;
	if (data->id == 2)
		size = 4;
	if (data->id == 3)
		size = 32;
	if (data->id == 4)
		size = 32;
	if (data->base == 8)
		size++;
	return (size);
}

char	*ft_dto_binary(t_data *data)
{
	char	*base_two;
	int		i;
	int		size;

	i = 0;
	size = ft_check_size(data);
	base_two = (char *)malloc(sizeof(char) * (size + 1));
	if (base_two)
	{
		while (i <= (size - 1))
			base_two[i++] = '0';
		base_two[i--] = '\0';
		if (data->n < 0)
			data->n = data->n * -1;
		ft_part_two(data, base_two, i);
	}
	return (base_two);
}
