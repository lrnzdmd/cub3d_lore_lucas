/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 05:16:04 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/26 07:17:20 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	open_door(t_cub	*data)
{
	t_v2d	coll;
	t_v2i	map;

	coll = data->gman.plyr.pos;
	coll = ft_sum_v2d(coll, ft_multiply_v2d(data->gman.plyr.dir, PLR_ACT_RNG));
	map.x = (int)coll.x;
	map.y = (int)coll.y;
	if (data->gman.map.map[map.y][map.x] == '2')
	{
		data->gman.map.map[map.y][map.x] = '0';
		data->gman.map.door_map[map.y][map.x]->open = true;
		data->gman.map.doors_open = true;
		trigger_screen_shake(data, 2.0, 0.5);
	}
}

void	pew_pew(t_cub *data)
{
	int		i;
	t_plyr	*plyr;

	plyr = &data->gman.plyr;
	if (plyr->state != SHOOT)
	{
		plyr->state = SHOOT;
		trigger_screen_shake(data, 30.0, 0.4);
		plyr->anim_timer = 0;
		i = -1;
		while (++i < data->gman.enemies_n)
		{
			if (data->gman.plyr.target)
			{
				data->gman.plyr.target->data.state = DEAD;
				return ;
			}
		}
	}
}
