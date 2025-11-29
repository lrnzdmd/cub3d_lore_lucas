/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 04:46:31 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 04:48:10 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	mouse_move_handler(int x, int y, t_cub *data)
{
	t_v2i	center;
	t_v2i	delta;

	(void)y;
	center.x = data->gfx.fr_bf.size.x * 0.5;
	center.y = data->gfx.fr_bf.size.y * 0.5;
	if (x == center.x && y == center.y)
		return (0);
	delta.x = x - center.x;
	delta.y = y - center.y;
	data->input.mouse_d.x = delta.x;
	data->input.mouse_d.y = delta.y;
	mlx_mouse_move(data->mlx, data->mlx_w, center.x,
		center.y);
	return (0);
}

void	mouse_change_pitch(t_cub *data)
{
	int	val;
	int	limit;

	val = data->input.mouse_d.y * 0.8;
	limit = data->gfx.fr_bf.size.y * 0.5;
	if (val != 0)
	{
		data->gman.plyr.pitch -= val;
		if (data->gman.plyr.pitch < -limit)
			data->gman.plyr.pitch = -limit;
		if (data->gman.plyr.pitch > limit)
			data->gman.plyr.pitch = limit;
		data->input.mouse_d.y = 0;
	}
}

int	mouse_key_handler(int keycode, int x, int y, t_cub *data)
{
	(void)data;
	(void)x;
	(void)y;
	if (keycode == 1 && data->gman.plyr.state == NORM)
		data->input.shoot = true;
	return (0);
}
