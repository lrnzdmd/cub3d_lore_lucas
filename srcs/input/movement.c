/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:48:43 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/16 05:32:51 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	movement_x(t_cub *data, t_v2d step, t_v2d coll, t_v2i map);
static void	movement_y(t_cub *data, t_v2d step, t_v2d coll, t_v2i map);

void	rotate_player(t_cub *data, bool left)
{
	double	rot;

	if (left)
		rot = -ROT_SPD * data->d_time;
	else
		rot = ROT_SPD * data->d_time;
	if (rot != 0.0)
	{
		data->gman.plyr.rot += rot;
		if (data->gman.plyr.rot < 0.0)
			data->gman.plyr.rot += 2.0 * M_PI;
		else if (data->gman.plyr.rot > 2.0 * M_PI)
			data->gman.plyr.rot -= 2.0 * M_PI;
		update_player_vectors(data);
	}
}

void	mouse_rotate_player(t_cub *data)
{
	double	rot;

	rot = data->input.mouse_dx * MOUSE_SENS * data->d_time;
	if (rot != 0.0)
	{
		data->gman.plyr.dir = ft_rotate_v2d(data->gman.plyr.dir, rot);
		data->gman.plyr.plane = ft_rotate_v2d(data->gman.plyr.plane, rot);
		data->input.mouse_dx = 0;
	}
}

static void	movement_x(t_cub *data, t_v2d step, t_v2d coll, t_v2i map)
{
	coll.x = data->gman.plyr.pos.x + step.x;
	if (step.x > 0)
		map.x = coll.x + PLR_HBOX_RD;
	else
		map.x = coll.x - PLR_HBOX_RD;
	map.y = data->gman.plyr.pos.y;
	if (coll.x > data->gman.map.size.x || coll.x < 0)
		return ;
	if (data->gman.map.map[map.y][map.x] != '1'
		&& data->gman.map.map[map.y][map.x] != '2')
		data->gman.plyr.pos.x = coll.x;
}

static void	movement_y(t_cub *data, t_v2d step, t_v2d coll, t_v2i map)
{
	coll.y = data->gman.plyr.pos.y + step.y;
	if (step.y > 0)
		map.y = coll.y + PLR_HBOX_RD;
	else
		map.y = coll.y - PLR_HBOX_RD;
	map.x = data->gman.plyr.pos.x;
	if (coll.y > data->gman.map.size.y - 1 || coll.y < 0)
		return ;
	if (data->gman.map.map[map.y][map.x] != '1'
		&& data->gman.map.map[map.y][map.x] != '2')
		data->gman.plyr.pos.y = coll.y;
}

void	move_fwd_bck(t_cub *data, bool fwd)
{
	t_v2d	step;
	t_v2d	coll;
	t_v2i	map;
	double	speed;

	speed = MOV_SPD * data->d_time;
	if (data->input.sprint)
		speed *= 2;
	step = ft_multiply_v2d(data->gman.plyr.dir, speed);
	if (!fwd)
		step = ft_multiply_v2d(step, -1.0);
	movement_x(data, step, coll, map);
	movement_y(data, step, coll, map);
}
