/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 06:29:54 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 04:53:50 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	idle_state(t_cub *data, t_ent *enemy)
{
	set_animation(enemy, &data->gfx.txt.sprts.enemy.idle);
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
	set_animation(enemy, &data->gfx.txt.sprts.enemy.walk);
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

	set_animation(enemy, &data->gfx.txt.sprts.enemy.walk);
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
	set_animation(enemy, &data->gfx.txt.sprts.enemy.attack);
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
		data->gman.plyr.hp -= 10;
		trigger_screen_shake(data, SCRSHK_INT_HURT, SCRSHK_DUR_HURT);
		enemy->data.st_timer = ENM_ATK_SPD;
	}
}

void	dead_state(t_cub *data, t_ent *enemy)
{
	set_animation(enemy, &data->gfx.txt.sprts.enemy.dead);
}
