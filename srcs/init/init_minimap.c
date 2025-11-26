/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 06:14:06 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/26 06:14:39 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
