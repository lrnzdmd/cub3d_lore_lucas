/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 04:04:23 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/22 03:13:32 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_window_size(t_cub *data)
{
	t_v2i	screen;
	void	*mlx;
	t_img_d	*frame;

	mlx = data->mlx;
	frame = &data->gfx.fr_bf;
	mlx_get_screen_size(mlx, &screen.x, &screen.y);
	if (screen.x < SCR_SZ_X)
		frame->size.x = screen.x - 10;
	else
		frame->size.x = SCR_SZ_X;
	if (screen.y < SCR_SZ_Y)
		frame->size.y = screen.y - 10;
	else
		frame->size.y = SCR_SZ_Y;
}

void	init_minimap_buffer(t_cub *data)
{
	t_img_d	*frame;
	t_img_d	*mn_map_bf;
	t_map	*map;

	frame = &data->gfx.fr_bf;
	map = &data->gman.map;
	mn_map_bf = &data->gfx.m_map;
	map->tile_size = (frame->size.x * (MINIMAP_SZ + 0.01)) / map->size.x;
	safe_mlx_new_img(data, mn_map_bf,
		map->size.x * map->tile_size, map->size.y * map->tile_size);
}

void	init_enemy_textures(t_cub *data)
{
	t_enm_txt	*text;

	text = &data->gfx.txt.sprts.enemy;
	safe_mlx_xpm_to_img(data, &text->attack[0],
		TXT_ENM_ATK_0, &text->attack[0].size);
	safe_mlx_xpm_to_img(data, &text->attack[1],
		TXT_ENM_ATK_1, &text->attack[1].size);
	safe_mlx_xpm_to_img(data, &text->walk[0],
		TXT_ENM_WALK_0, &text->walk[0].size);
	safe_mlx_xpm_to_img(data, &text->walk[1],
		TXT_ENM_WALK_0, &text->walk[1].size);
}

void	init_gfx_data(t_cub	*data)
{
	t_img_d	*frame;
	t_img_d	*door_txt;

	frame = &data->gfx.fr_bf;
	door_txt = &data->gfx.txt.wall.dr;
	data->lst_frm_time = get_time_in_sec();
	data->d_time = 0;
	set_window_size(data);
	data->mlx_w = safe_mlx_new_window(data,
			frame->size.x, frame->size.y, "cub3d");
	safe_mlx_new_img(data, frame, frame->size.x, frame->size.y);
	safe_mlx_xpm_to_img(data, door_txt, TXT_DOOR, &door_txt->size);
	init_enemy_textures(data);
	init_minimap(data);
}

void	init_minimap(t_cub *data)
{
	t_v2i	i;
	t_img_d	*minimap;
	t_map	map;

	init_minimap_buffer(data);
	minimap = &data->gfx.m_map;
	map = data->gman.map;
	drawrect_to_img(minimap, (t_v2i){0, 0},
		minimap->size, 0x00000066);
	i.y = -1;
	while (++i.y < map.size.y)
	{
		i.x = -1;
		while (++i.x < map.size.x)
		{
			if (map.map[i.y][i.x] == '1')
				draw_map_tile(data, minimap, i);
		}
	}
}
