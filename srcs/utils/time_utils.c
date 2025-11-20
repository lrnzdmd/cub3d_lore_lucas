/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:58:27 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/16 06:01:16 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

double	get_time_in_sec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec + (double)tv.tv_usec / 1000000.0);
}

void	calc_delta_time(t_cub *data)
{
	double	curr_time;

	curr_time = get_time_in_sec();
	data->d_time = curr_time - data->lst_frm_time;
	data->lst_frm_time = curr_time;
	if (data->d_time > (1.0 / 15.0))
		data->d_time = (1.0 / 15.0);
}
