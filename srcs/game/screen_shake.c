/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shake.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 05:39:20 by luferna3          #+#    #+#             */
/*   Updated: 2025/11/26 08:08:11 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdio.h>

void	trigger_screen_shake(t_cub *data, double intensity, double duration)
{
	data->shake.active = true;
	data->shake.intensity = intensity;
	data->shake.duration = duration;
	data->shake.time = 0.0;
}

void	update_screen_shake(t_cub *data)
{
	double	shake_amount;
	
	if (data->shake.last_offset != 0.0)
	{
		data->gman.plyr.rot -= data->shake.last_offset;
		data->shake.last_offset = 0.0;
	}
	if (!data->shake.active)
	{
		data->shake.offset = 0.0;
		update_player_vectors(data);
		return ;
	}
	data->shake.time += data->d_time;
	shake_amount = data->shake.intensity * 
		(1.0 - (data->shake.time / data->shake.duration));
	if (data->shake.time >= data->shake.duration)
	{
		data->shake.active = false;
		data->shake.offset = 0.0;
		update_player_vectors(data);
		return ;
	}
	data->shake.offset = ((double)rand() / RAND_MAX * 2.0 - 1.0) 
		* shake_amount * 0.01;
	data->gman.plyr.rot += data->shake.offset;
	data->shake.last_offset = data->shake.offset;
	update_player_vectors(data);
}
