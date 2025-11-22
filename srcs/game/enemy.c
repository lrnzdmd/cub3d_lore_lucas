/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 05:08:50 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/22 06:07:16 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	enemy_state_update(t_cub *data, t_ent	*enemy)
{
	enemy->data.st_timer -= data->d_time;
	enemy->pl_dist = ft_distance_sq_v2d(data->gman.plyr.pos, enemy->pos);
	if (enemy->pl_dist < ENM_AGGR_RANGE)
	{
		if (enemy->pl_dist < ENM_ATK_RANGE)
			enemy->data.state = ATTACK;
		else
			enemy->data.state = CHASE;
	}
	else
	{
		if (enemy->data.st_timer > 0)
			return ;
		else if (rand() % 3 == 0)
			enemy->data.state = IDLE;
		else
			enemy->data.state = PATROL;
		enemy->data.st_timer = ENM_AI_TIMER;
	}
}

void	update_enemy_dir(t_ent *enemy)
{
	double	rot;

	rot = ((double)rand() / RAND_MAX) * 2 * M_PI;
	enemy->data.dir.x = cos(rot);
	enemy->data.dir.y = sin(rot);
}

static void	enemy_movement_x(t_cub *data, t_ent *enemy, t_v2d step, t_v2d coll)
{
	t_v2i	map;

	coll.x = enemy->pos.x + step.x;
	if (step.x > 0)
		map.x = coll.x + ENM_HBOX_RADIUS;
	else
		map.x = coll.x - ENM_HBOX_RADIUS;
	map.y = enemy->pos.y;
	if (coll.x > data->gman.map.size.x || coll.x < 0)
		return ;
	if (data->gman.map.map[map.y][map.x] != '1'
		&& data->gman.map.map[map.y][map.x] != '2')
		enemy->pos.x = coll.x;
	else
		update_enemy_dir(enemy);
}

static void	enemy_movement_y(t_cub *data, t_ent *enemy, t_v2d step, t_v2d coll)
{
	t_v2i	map;

	coll.y = enemy->pos.y + step.y;
	if (step.y > 0)
		map.y = coll.y + ENM_HBOX_RADIUS;
	else
		map.y = coll.y - ENM_HBOX_RADIUS;
	map.x = enemy->pos.x;
	if (coll.y > data->gman.map.size.y || coll.y < 0)
		return ;
	if (data->gman.map.map[map.y][map.x] != '1'
		&& data->gman.map.map[map.y][map.x] != '2')
		enemy->pos.y = coll.y;
	else
		update_enemy_dir(enemy);
}

void	enemy_move(t_cub *data, t_ent *enemy)
{
	t_v2d	step;
	t_v2d	coll;
	double	speed;

	speed = ENM_MOV_SPD * data->d_time;
	step = ft_multiply_v2d(enemy->data.dir, speed);
	enemy_movement_x(data, enemy, step, coll);
	enemy_movement_y(data, enemy, step, coll);
}

void	patrol_state(t_cub *data, t_ent *enemy)
{
	if (enemy->data.st_timer == ENM_AI_TIMER)
		update_enemy_dir(enemy);
	enemy_move(data, enemy);
}

void	chase_state(t_cub *data, t_ent	*enemy)
{
	t_v2d	dist_vec;
	double	dist_len;

	dist_len = sqrt(enemy->pl_dist);
	if (dist_len < ENM_ATK_RANGE)
		return ;
	dist_vec.x = data->gman.plyr.pos.x - enemy->pos.x;
	dist_vec.y = data->gman.plyr.pos.y - enemy->pos.y;
	enemy->data.dir.x = dist_vec.x / dist_len;
	enemy->data.dir.y = dist_vec.y / dist_len;
	enemy_move(data, enemy);
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

void	enemy_action(t_cub *data, t_ent	*enemy)
{
	if (enemy->data.state == PATROL)
		patrol_state(data, enemy);
	if (enemy->data.state == CHASE)
		chase_state(data, enemy);
	if (enemy->data.state == ATTACK)
		attack_state(data, enemy);
}
