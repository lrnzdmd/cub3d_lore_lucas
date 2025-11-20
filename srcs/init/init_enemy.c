/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 05:13:32 by lorenzo           #+#    #+#             */
/*   Updated: 2025/11/20 05:16:25 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_enemy(t_ent *enemy, t_v2i	i);

void	init_enemies(t_cub *data)
{
	int		j;
	t_v2i	i;

	if (data->gman.enemies_n < 1)
		return ;
	data->gman.enemies = safe_calloc(data, data->gman.enemies_n, sizeof(t_ent));
	j = 0;
	i.y = -1;
	while (++i.y < data->gman.map.size.y)
	{
		i.x = -1;
		while (++i.x < data->gman.map.size.x)
		{
			if (data->gman.map.map[i.y][i.x] == 'Z')
			{
				data->gman.map.map[i.y][i.x] = '0';
				init_enemy(&data->gman.enemies[j], i);
				j++;
			}
		}
	}
}

static void	init_enemy(t_ent *enemy, t_v2i	i)
{
	enemy->pos.x = i.x + 0.5;
	enemy->pos.y = i.y + 0.5;
	enemy->type = ENEMY;
	enemy->data.state = IDLE;
	enemy->data.dir = (t_v2d){1, 0};	
}