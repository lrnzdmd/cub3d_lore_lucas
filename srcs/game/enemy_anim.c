/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:11:24 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/23 21:53:40 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	enemy_animator(t_cub *data, t_ent *enemy)
{
	double	speed;

	if (enemy->data.state == IDLE)
	{
		enemy->sprt = &data->gfx.txt.sprts.enemy.idle;
		enemy->data.anim_timer = 0;
		enemy->data.anim_frm = 0;
		return ;
	}
	if (enemy->data.state == DEAD)
	{
		enemy->sprt = &data->gfx.txt.sprts.enemy.dead;
		enemy->data.anim_timer = 0;
		enemy->data.anim_frm = 0;
		return ;
	}
	else
	{
		if (enemy->data.state == ATTACK)
			speed = ANM_SPD_ENM_ATK;
		else
			speed = ANM_SPD_ENM_WALK;
	}
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
