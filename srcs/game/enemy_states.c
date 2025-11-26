/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 06:29:54 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/26 18:39:39 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	enemy_state_update(t_cub *data, t_ent	*enemy)
{
	if (enemy->data.state == DEAD)
		return ;
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

	if (enemy->pl_dist < (ENM_ATK_RANGE * ENM_ATK_RANGE))
		return ;
	dist_len = sqrt(enemy->pl_dist);
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
		trigger_screen_shake(data, SCRSHK_INT_HURT, SCRSHK_DUR_HURT);
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
