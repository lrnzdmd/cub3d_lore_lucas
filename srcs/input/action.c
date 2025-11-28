/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 05:16:04 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 00:29:31 by lde-medi         ###   ########.fr       */
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
		trigger_screen_shake(data, SCRSHK_INT_DOOR, SCRSHK_DUR_DOOR);
	}
}

void	pew_pew(t_cub *data)
{
	int		i;

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

