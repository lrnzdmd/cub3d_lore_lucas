/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_doors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 00:37:15 by lorenzo           #+#    #+#             */
/*   Updated: 2025/11/20 00:43:25 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_doors(t_cub *data);
static bool	check_valid_door(t_tmp *tmp, char **map, int x, int y);

bool	validate_map_doors(t_cub *data)
{
	int		j;
	t_v2i	i;

	init_doors(data);
	i.y = -1;
	j = 0;
	while (++i.y < data->gman.map.size.y)
	{
		i.x = -1;
		while (++i.x < data->gman.map.size.x)
		{
			if (data->gman.map.map[i.y][i.x] == '2')
			{
				if (!check_valid_door(&data->tmp, data->gman.map.map, i.x, i.y))
					return (false);
				data->gman.map.doors[j].pos = ft_set_v2i(i.x, i.y);
				data->gman.map.doors[j].hor = data->tmp.lst_dr_h;
				data->gman.map.door_map[i.y][i.x] = &data->gman.map.doors[j];
				j++;
			}
		}
	}
	return (true);
}

static bool	check_valid_door(t_tmp *tmp, char **map, int x, int y)
{
	bool	h_walls;
	bool	v_walls;

	h_walls = (map[y][x - 1] == '1' && map[y][x + 1] == '1');
	v_walls = (map[y - 1][x] == '1' && map[y + 1][x] == '1');
	if (h_walls ^ v_walls)
	{
		if (h_walls)
			tmp->lst_dr_h = H;
		else
			tmp->lst_dr_h = V;
		return (true);
	}
	return (false);
}

static void	init_doors(t_cub *data)
{
	int	j;

	data->gman.map.doors = safe_calloc(data,
			data->gman.map.doors_n, sizeof(t_door));
	data->gman.map.door_map = safe_calloc(data,
			data->gman.map.size.y, sizeof(t_door *));
	j = -1;
	while (++j < data->gman.map.size.y)
		data->gman.map.door_map[j] = safe_calloc(data,
				data->gman.map.size.x, sizeof(t_door *));
}
