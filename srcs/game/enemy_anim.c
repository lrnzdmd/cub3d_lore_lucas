/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:11:24 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 08:21:36 by lde-medi         ###   ########.fr       */
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

void	set_animation(t_ent *enemy, t_anim *anim)
{
	if (enemy->anim == anim)
		return ; // Stessa animazione, non resettare nulla
	enemy->anim = anim;
	enemy->data.anim_frm = 0;
	enemy->data.anim_timer = 0;
}
