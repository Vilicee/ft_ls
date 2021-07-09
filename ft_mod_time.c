/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@hive.fi>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:11:29 by wvaara            #+#    #+#             */
/*   Updated: 2021/07/07 17:56:36 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	ft_too_old(t_no_flags *data, char *m_time)
{
	int	i;
	int	ii;

	i = 0;
	ii = 3;
	data->year[4] = '\0';
	data->old = '1';
	while (m_time[i] != '\n')
		i++;
	i--;
	while (ii >= 0)
		data->year[ii--] = m_time[i--];
}

void	ft_mod_time(t_no_flags *data, struct stat *stats)
{
	char	*m_time;

	data->k = 4;
	data->kk = 0;
	data->old = '0';
	data->now = time(0);
	data->then = stats->st_mtime;
	m_time = ctime((const time_t *)&stats->st_mtimespec);
	if (data->now - data->then > 15780000)
		ft_too_old(data, m_time);
	while (data->k < 7)
		data->month[data->kk++] = m_time[data->k++];
	data->month[data->kk] = '\0';
	data->kk = 0;
	while (m_time[data->k] == ' ')
		data->k++;
	while (m_time[data->k] != ' ')
		data->date[data->kk++] = m_time[data->k++];
	data->date[data->kk] = '\0';
	data->kk = 0;
	while (m_time[data->k] == ' ')
		data->k++;
	while (data->kk < 5)
		data->hour_min[data->kk++] = m_time[data->k++];
	data->hour_min[data->kk] = '\0';
}
