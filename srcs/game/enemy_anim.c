/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:11:24 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 04:53:54 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	enemy_animator(t_cub *data, t_ent *enemy)
{
	t_anim	*anim;

	anim = enemy->anim;
	if (!anim || !anim->frame)
		return ;
	enemy->data.anim_timer += data->d_time;
	if (enemy->data.anim_timer >= anim->speed)
	{
		enemy->data.anim_timer = 0;
		if (anim->loop)
			enemy->data.anim_frm = (enemy->data.anim_frm + 1) % anim->frm_n;
		else
		{
			if (enemy->data.anim_frm < anim->frm_n - 1)
				enemy->data.anim_frm++;
		}
	}
	enemy->sprt = &anim->frame[enemy->data.anim_frm];
}

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

void	enemy_update(t_cub *data, t_ent *enemy)
{
	static t_en_state_func	states[5] = {idle_state, patrol_state, chase_state,
		attack_state, dead_state};

	states[enemy->data.state](data, enemy);
}

void	set_animation(t_ent *enemy, t_anim *anim)
{
	if (enemy->anim == anim)
		return ;
	enemy->anim = anim;
	enemy->data.anim_frm = 0;
	enemy->data.anim_timer = 0;
}
