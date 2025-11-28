/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 06:29:54 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 06:43:21 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	change_state(t_ent *enemy, t_enm_st state)
{
	enemy->data.state = state;
	if (state == IDLE)
		enemy->data.st_timer = 2;
	else if (state == PATROL)
	{
		update_enemy_dir(enemy);
		enemy->data.st_timer = 3.5;
	}
	else if (state == ATTACK)
		enemy->data.st_timer = 0.5;
}
void	idle_state(t_cub *data, t_ent *enemy)
{
	enemy->pl_dist = ft_distance_sq_v2d(data->gman.plyr.pos, enemy->pos);
	if (enemy->pl_dist < (ENM_AGGR_RANGE))
	{
		change_state(enemy, CHASE);
		return ;
	}
	enemy->data.st_timer -= data->d_time;
	if (enemy->data.st_timer <= 0)
	{
		if (rand() % 2 == 0)
			change_state(enemy, PATROL);
		else
			enemy->data.st_timer = 2;
	}
}

void	patrol_state(t_cub *data, t_ent *enemy)
{
	enemy->pl_dist = ft_distance_sq_v2d(data->gman.plyr.pos, enemy->pos);
	if (enemy->pl_dist < ENM_AGGR_RANGE)
	{
		change_state(enemy, CHASE);
		return ;
	}
	enemy_move(data, enemy);
	enemy->data.st_timer -= data->d_time;
	if (enemy->data.st_timer <= 0)
	{
		if (rand() % 2 == 0)
			change_state(enemy, IDLE);
		else
		{
			update_enemy_dir(enemy);
			enemy->data.st_timer = 3;
		}
	}
}

void	chase_state(t_cub *data, t_ent *enemy)
{
	t_v2d	dist_vec;
	double	dist_len;	

	enemy->pl_dist = ft_distance_sq_v2d(data->gman.plyr.pos, enemy->pos);
	if (enemy->pl_dist < (ENM_ATK_RANGE * ENM_ATK_RANGE))
	{
		change_state(enemy, ATTACK);
		return ;
	}
	if (enemy->pl_dist >= (ENM_AGGR_RANGE * ENM_AGGR_RANGE) * 1.5)
	{
		change_state(enemy, PATROL);
		return ;
	}
	dist_len = sqrt(enemy->pl_dist);
	dist_vec.x = data->gman.plyr.pos.x - enemy->pos.x;
	dist_vec.y = data->gman.plyr.pos.y - enemy->pos.y;
	enemy->data.dir.x = dist_vec.x / dist_len;
	enemy->data.dir.y = dist_vec.y / dist_len;
	enemy_move(data, enemy);
}

void	attack_state(t_cub *data, t_ent *enemy)
{
	enemy->pl_dist = ft_distance_sq_v2d(data->gman.plyr.pos, enemy->pos);
	if (enemy->pl_dist > (ENM_ATK_RANGE * ENM_ATK_RANGE))
	{
		change_state(enemy, CHASE);
		return ;
	}
	if (enemy->data.st_timer > 0)
		enemy->data.st_timer -= data->d_time;
	else
	{
		data->gman.plyr.hp -= 1;
		trigger_screen_shake(data, SCRSHK_INT_HURT, SCRSHK_DUR_HURT);
		enemy->data.st_timer = ENM_ATK_SPD;
	}
}

void	enemy_action(t_cub *data, t_ent *enemy)
{
	static t_state_func	states[4] = {idle_state, patrol_state, chase_state,
		attack_state};

	if (enemy->data.state != DEAD)
		states[enemy->data.state](data, enemy);
}
