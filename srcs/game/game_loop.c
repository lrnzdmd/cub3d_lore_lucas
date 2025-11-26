/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:45:23 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/26 16:47:58 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	game_loop(t_cub *data)
{
	double	time_start;
	double	time_end;

	time_start = get_time_in_sec();
	calc_delta_time(data);
	update_enemies(data);
	update_screen_shake(data);
	player_animator(data);
	input_manager(data);
	door_check(data);
	draw_game(data);
	if (data->gman.plyr.hp <= 0)
	{
		ft_printf("Game Over.\n");
		exit_game(data);
	}
	time_end = get_time_in_sec() - time_start;
	if (time_end < TARGET_FR_TIME)
		usleep(((TARGET_FR_TIME - time_end) * 1000000.0));
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
