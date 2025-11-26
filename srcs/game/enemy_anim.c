/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:11:24 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/26 06:21:25 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	anim_idle_dead(t_cub *data, t_ent *enemy);

void	enemy_animator(t_cub *data, t_ent *enemy)
{
	double	speed;

	if (enemy->data.state == IDLE || enemy->data.state == DEAD)
	{
		anim_idle_dead(data, enemy);
		return ;
	}
	if (enemy->data.state == ATTACK)
		speed = ANM_SPD_ENM_ATK;
	else
		speed = ANM_SPD_ENM_WALK;
	enemy->data.anim_timer += data->d_time;
	if (enemy->data.anim_timer >= speed)
	{
		enemy->data.anim_timer = 0;
		enemy->data.anim_frm = (enemy->data.anim_frm + 1) % 2;
	}
	if (enemy->data.state == ATTACK)
		enemy->sprt = &data->gfx.txt.sprts.enemy.attack[enemy->data.anim_frm];
	else
		enemy->sprt = &data->gfx.txt.sprts.enemy.walk[enemy->data.anim_frm];
}

static void	anim_idle_dead(t_cub *data, t_ent *enemy)
{
	if (enemy->data.state == IDLE)
		enemy->sprt = &data->gfx.txt.sprts.enemy.idle;
	else
		enemy->sprt = &data->gfx.txt.sprts.enemy.dead;
	enemy->data.anim_timer = 0;
	enemy->data.anim_frm = 0;
}
