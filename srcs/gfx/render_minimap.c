/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:05:31 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/20 00:36:04 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_doors(t_cub *data)
{
	int		i;
	t_door	*doors;

	i = -1;
	doors = data->gman.map.doors;
	while (++i < data->gman.map.doors_n)
	{
		if (!doors[i].open)
			draw_map_tile(data, &data->gfx.fr_bf, doors[i].pos, true);
	}
}

void	draw_enemies_minimap(t_cub *data)
{
	int		i;
	t_v2i	pos;
	t_ent	*enemy;

	i = -1;
	enemy = data->gman.enemies;
	while (++i < data->gman.enemies_n)
	{
		if (enemy[i].type == ENEMY)
		{
			pos = map_to_pixel_coords(data->gman.map, enemy[i].pos);
			drawrect_to_img(&data->gfx.fr_bf, (t_v2i){pos.x - 2,
				pos.y - 2}, (t_v2i){pos.x + 2, pos.y + 2}, 0x00ff0000);
		}
	}
}

void	draw_minimap(t_cub *data)
{
	t_v2i	i;
	t_img_d	*frm;
	t_img_d	*buf;

	frm = &data->gfx.fr_bf;
	buf = &data->gfx.m_map;
	i.y = -1;
	while (++i.y < buf->size.y)
	{
		i.x = -1;
		while (++i.x < buf->size.x)
			*(unsigned int *)calc_dest_addr(frm, i)
			= *(unsigned int *)calc_dest_addr(buf, i);
	}
	draw_doors(data);
	draw_enemies_minimap(data);
	draw_player_minimap(data);
}

void	draw_player_minimap(t_cub *data)
{
	t_img_d	*minimap;
	t_v2d	dir_d;
	t_v2i	pl_pix;
	t_v2i	dir;
	t_plyr	plyr;

	plyr = data->gman.plyr;
	minimap = &data->gfx.fr_bf;
	pl_pix = map_to_pixel_coords(data->gman.map, plyr.pos);
	dir_d.x = plyr.pos.x + (plyr.dir.x / 2);
	dir_d.y = plyr.pos.y + (plyr.dir.y / 2);
	dir = map_to_pixel_coords(data->gman.map, dir_d);
	drawline_to_img(minimap, pl_pix, dir, 0x00707012);
	drawrect_to_img(minimap, (t_v2i){pl_pix.x - 2,
		pl_pix.y - 2}, (t_v2i){pl_pix.x + 2, pl_pix.y + 2}, 0x0000ff00);
}

void	draw_map_tile(t_cub *data, t_img_d	*img, t_v2i map, bool door)
{
	t_v2i	pos;
	t_v2i	end;
	int		tile_size;

	tile_size = data->gman.map.tile_size;
	pos = map_to_pixel_coords(data->gman.map, (t_v2d){map.x, map.y});
	if (door)
	{
		if (data->gman.map.door_map[map.y][map.x]->hor)
		{
			pos.x += (tile_size / 2) - (tile_size / 16);
			end.y = pos.y + tile_size;
			end.x = pos.x + (tile_size / 8);
		}
		else
		{
			pos.y += (tile_size / 2) - (tile_size / 16);
			end.x = pos.x + tile_size;
			end.y = pos.y + (tile_size / 8);
		}
		drawrect_to_img(img, pos, end, MAP_CLR_DR);
	}
	else
		drawrect_to_img(img, pos,
			(t_v2i){pos.x + tile_size, pos.y + tile_size}, MAP_CLR_WL);
}
