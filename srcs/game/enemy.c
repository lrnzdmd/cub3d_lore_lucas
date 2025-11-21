/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 05:08:50 by lorenzo           #+#    #+#             */
/*   Updated: 2025/11/21 03:26:01 by lorenzo          ###   ########.fr       */
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
		if (enemy[i].pl_dist < ENM_AGGR_RANGE)
		{
			if (enemy[i].pl_dist < ENM_ATK_RANGE)
				enemy[i].data.state = ATTACK;
			else
				enemy[i].data.state = CHASE;
		}
		else
		{
			if (enemy[i].data.st_timer > 0)
				continue ;
			else if (rand() % 3 == 0)
				enemy[i].data.state = IDLE;
			else
				enemy[i].data.state = PATROL;
			enemy[i].data.st_timer = ENM_AI_TIMER;
		}
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

void	chase_state(t_cub *data, t_ent	*enemy)
{
	t_v2d	dist_vec;
	double	dist_len;
	t_v2d	step;
	t_v2d	coll;
	t_v2i	map;

	dist_vec.x = data->gman.plyr.pos.x - enemy->pos.x;
	dist_vec.y = data->gman.plyr.pos.y - enemy->pos.y;
	dist_len = sqrt(dist_vec.x * dist_vec.x + dist_vec.y * dist_vec.y);
	if (dist_len < ENM_ATK_RANGE)
		return ;
	enemy->data.dir.x = dist_vec.x / dist_len;
	enemy->data.dir.y = dist_vec.y / dist_len;
	step.x = enemy->data.dir.x * (ENM_MOV_SPD * data->d_time);
	step.y = enemy->data.dir.y * (ENM_MOV_SPD * data->d_time);
	if (enemy->data.dir.x > 0)
		coll.x = enemy->pos.x + step.x + ENM_HBOX_RADIUS;
	else
		coll.x = enemy->pos.x + step.x - ENM_HBOX_RADIUS;
	if (enemy->data.dir.y > 0)
		coll.y = enemy->pos.y + step.y + ENM_HBOX_RADIUS;
	else
		coll.y = enemy->pos.y + step.y - ENM_HBOX_RADIUS;
	map.x = (int)coll.x;
	map.y = (int)coll.y;
	if (data->gman.map.map[map.y][map.x] == '0')
	{
		enemy->pos.x += step.x;
		enemy->pos.y += step.y;
	}
}

void	attack_state(t_cub *data, t_ent	*enemy)
{
	if (enemy->data.st_timer <= 0)
	{
		data->gman.plyr.hp -= 1;
		enemy->data.st_timer = ENM_ATK_SPD;	
	}
	else
		return ;
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
			chase_state(data, &enemy[i]);
		if (enemy[i].data.state == ATTACK)
			attack_state(data, &enemy[i]);
	}
}
