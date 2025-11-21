/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 05:08:50 by lorenzo           #+#    #+#             */
/*   Updated: 2025/11/21 00:37:37 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update_enemy_states(t_cub *data, t_ent	*enemy, int	enm_n)
{
	int	i;

	i = -1;
	while (++i < enm_n)
	{
		enemy[i].data.st_timer -= data->d_time;
		enemy[i].pl_dist = ft_distance_sq_v2d(data->gman.plyr.pos, enemy[i].pos);
		if (enemy[i].pl_dist < 2)
		{
			if (enemy[i].pl_dist < ENM_ATK_RANGE)
				enemy[i].data.state = ATTACK;
			else
				enemy[i].data.state = CHASE;
			continue ;
		}
		if (enemy[i].data.st_timer > 0)
			continue ;
		if (rand() % 3 == 0)
			enemy[i].data.state = IDLE;
		else
			enemy[i].data.state = PATROL;
		enemy[i].data.st_timer = ENM_AI_TIMER;
	}
}

void	update_enemy_dir(t_ent *enemy)
{
	double	rot;

	rot = ((double)rand() / RAND_MAX) * 2 * M_PI;
	enemy->data.dir.x = cos(rot);
	enemy->data.dir.y = sin(rot);
}

void	state_patrol(t_cub *data, t_ent *enemy)
{
	t_v2d	step;
	t_v2d	coll;
	t_v2i	map;

	if (enemy->data.st_timer == ENM_AI_TIMER)
		update_enemy_dir(enemy);
	step.x = enemy->data.dir.x * (ENM_MOV_SPD * data->d_time);
	step.y = enemy->data.dir.y * (ENM_MOV_SPD * data->d_time);
	coll.x = enemy->pos.x + step.x;
	coll.y = enemy->pos.y + step.y;
	if (step.x > 0)
		map.x = coll.x + ENM_HBOX_RADIUS;
	else
		map.x = coll.x - ENM_HBOX_RADIUS;
	if (step.y > 0)
		map.y = coll.y + ENM_HBOX_RADIUS;
	else
		map.y = coll.y - ENM_HBOX_RADIUS;
	if (data->gman.map.map[map.y][map.x] == '0')
	{
		enemy->pos.x += step.x;
		enemy->pos.y += step.y;
	}
	else
		update_enemy_dir(enemy);
}

void	enemy_action(t_cub *data, t_ent	*enemy, int	enm_n)
{
	int	i;

	i = -1;
	(void)data;
	while (++i < enm_n)
	{
		if (enemy[i].data.state == IDLE)
			continue ;
		if (enemy[i].data.state == PATROL)
			state_patrol(data, &enemy[i]);
		if (enemy[i].data.state == CHASE)
			ft_printf("%d is CHASING!\n", i);
		if (enemy[i].data.state == ATTACK)
			ft_printf("%d is ATTACKING!\n", i);
	}
}
