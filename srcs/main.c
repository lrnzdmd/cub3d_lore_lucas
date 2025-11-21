/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 05:30:54 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/20 14:42:11 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	draw_background(t_cub	*data)
{
	int		i;
	int		total_pix;
	int		*addr;
	t_img_d	*frm;

	frm = &data->gfx.fr_bf;
	addr = (int *)frm->addr;
	total_pix = (frm->size.x * frm->size.y);
	i = -1;
	while (++i < total_pix / 2)
		addr[i] = data->gfx.ceil_c.color;
	while (i < total_pix)
		addr[i++] = data->gfx.grnd_c.color;
	return (0);
}

void	door_check(t_cub	*data)
{
	t_plyr	plyr;
	t_door	*doors;
	t_v2d	door_cntr;
	int		i;

	doors = data->gman.map.doors;
	plyr = data->gman.plyr;
	if (!data->gman.map.doors_open)
		return ;
	data->gman.map.doors_open = false;
	i = -1;
	while (++i < data->gman.map.doors_n)
	{
		if (doors[i].open)
		{
			door_cntr = (t_v2d){doors[i].pos.x + 0.5, doors[i].pos.y + 0.5};
			if (ft_distance_sq_v2d(plyr.pos, door_cntr) > 2.25)
			{
				data->gman.map.map[doors[i].pos.y][doors[i].pos.x] = '2';
				data->gman.map.doors[i].open = false;
			}
			else
				data->gman.map.doors_open = true;
		}
	}
}

int	game_loop(t_cub *data)
{
	double	time_start;
	double	time_end;

	time_start = get_time_in_sec();
	calc_delta_time(data);
	update_enemy_states(data, data->gman.enemies, data->gman.enemies_n);
	enemy_action(data, data->gman.enemies, data->gman.enemies_n);
	input_manager(data);
	door_check(data);
	draw_background(data);
	if (data->input.map_toggle)
	{
		draw_minimap(data);
		draw_player_minimap(data);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_w,
		data->gfx.fr_bf.img_p, 0, 0);
	time_end = get_time_in_sec() - time_start;
	if (time_end < TARGET_FR_TIME)
		usleep(((TARGET_FR_TIME - time_end) * 1000000.0));
	return (0);
}

int	main(int ac, char	**av)
{
	static t_cub	data;

	data.mlx = safe_mlx_init(&data);
	parse_cub3d(&data, ac, av);
	init_gfx_data(&data);
	init_player(&data);
	init_enemies(&data);
	mlx_hook(data.mlx_w, 17, 0, exit_game, &data);
	mlx_hook(data.mlx_w, 2, 1L << 0, key_press_handler, &data);
	mlx_hook(data.mlx_w, 3, 1L << 1, key_release_handler, &data);
	mlx_hook(data.mlx_w, 6, 1L << 6, mouse_move_handler, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
}
