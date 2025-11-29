/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:18:35 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 03:45:32 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update_player_vectors(t_cub *data)
{
	data->gman.plyr.dir.x = cos(data->gman.plyr.rot);
	data->gman.plyr.dir.y = sin(data->gman.plyr.rot);
	data->gman.plyr.plane.x = -sin(data->gman.plyr.rot) * FOV_PLANE;
	data->gman.plyr.plane.y = cos(data->gman.plyr.rot) * FOV_PLANE;
}

void	get_player_start_rot(t_cub *data, char d)
{
	t_plyr	*plyr;

	plyr = &data->gman.plyr;
	if (d == 'N')
		plyr->rot = M_PI * 0.5;
	else if (d == 'S')
		data->gman.plyr.rot = 3.0 * M_PI * 0.5;
	else if (d == 'W')
		data->gman.plyr.rot = M_PI;
	else
		data->gman.plyr.rot = 0.0;
	update_player_vectors(data);
}

void	get_player_start_pos(t_cub *data)
{
	t_v2i	i;
	t_map	map;
	t_plyr	*plyr;

	map = data->gman.map;
	plyr = &data->gman.plyr;
	i.y = -1;
	while (++i.y < map.size.y)
	{
		i.x = -1;
		while (++i.x < map.size.x)
		{
			if (is_direction_char(map.map[i.y][i.x]))
			{
				plyr->pos.y = i.y + 0.5f;
				plyr->pos.x = i.x + 0.5f;
				get_player_start_rot(data, map.map[i.y][i.x]);
				map.map[i.y][i.x] = '0';
			}
		}
	}
}

void	init_mouse_controls(t_cub *data)
{
	mlx_mouse_hide(data->mlx, data->mlx_w);
	mlx_mouse_move(data->mlx, data->mlx_w,
		data->gfx.fr_bf.size.x * 0.5,
		data->gfx.fr_bf.size.y * 0.5);
}

void	init_player(t_cub	*data)
{
	get_player_start_pos(data);
	data->gman.plyr.hp = PLYR_MAX_HP;
	data->gman.plyr.ammo = PLYR_MAX_AMMO;
}
