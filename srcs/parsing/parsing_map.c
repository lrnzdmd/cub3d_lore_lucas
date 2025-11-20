/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:54:03 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/20 00:47:04 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static bool	validate_map_chars(t_cub	*data);
static bool	validate_map_borders(t_cub	*data);
static bool	check_open_borders(t_cub *data, char **map, int x, int y);
static void	count_glyphs(t_cub *data);

void	parse_map(t_cub	*data)
{
	init_map(data);
	if (!validate_map_chars(data))
		exit_with_error(data, ERR_MAP_INV_CH, 1);
	if (!validate_map_borders(data))
		exit_with_error(data, ERR_MAP_INV_BRD, 1);
	count_glyphs(data);
	if (!validate_map_doors(data))
		exit_with_error(data, ERR_MAP_INV_DR, 1);
}

static void	count_glyphs(t_cub *data)
{
	t_v2i	i;

	data->gman.map.doors_n = 0;
	data->gman.enemies_n = 0;
	i.y = -1;
	while (++i.y < data->gman.map.size.y)
	{
		i.x = -1;
		while (++i.x < data->gman.map.size.x)
		{
			if (data->gman.map.map[i.y][i.x] == '2')
				data->gman.map.doors_n++;
			else if (data->gman.map.map[i.y][i.x] == 'Z')
				data->gman.enemies_n++;
		}
	}
}

static bool	validate_map_chars(t_cub	*data)
{
	bool	pl_st;
	t_list	*tmp;

	tmp = data->tmp.lst;
	pl_st = false;
	while (tmp)
	{
		data->tmp.str_1 = (char *)tmp->content;
		while (*data->tmp.str_1)
		{
			if (!is_valid_map_char(*data->tmp.str_1)
				|| (is_direction_char(*data->tmp.str_1) && pl_st))
				return (data->tmp.str_1 = NULL, false);
			if (is_direction_char(*data->tmp.str_1))
				pl_st = true;
			data->tmp.str_1++;
		}
		tmp = tmp->next;
	}
	data->tmp.str_1 = NULL;
	return (pl_st);
}

static bool	validate_map_borders(t_cub	*data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->gman.map.size.y)
	{
		j = -1;
		while (++j < data->gman.map.size.x)
		{
			if (!check_open_borders(data, data->gman.map.map, j, i))
				return (false);
		}
	}
	return (true);
}

static bool	check_open_borders(t_cub *data, char **map, int x, int y)
{
	bool	touch_walls;

	if (map[y][x] == '1' || map[y][x] == ' ')
		return (true);
	if (x == 0 || x == data->gman.map.size.x - 1
		|| y == 0 || y == data->gman.map.size.y - 1)
		return (false);
	touch_walls = (
			map[y][x - 1] == ' '
			|| map[y][x + 1] == ' '
			|| map[y - 1][x] == ' '
			|| map[y + 1][x] == ' ');
	return (!touch_walls);
}
