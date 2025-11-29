/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:14:40 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 01:56:27 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	pl_change_state(t_plyr *plyr, t_pl_st state)
{
	plyr->state = state;
	if (state == SHOOT)
		plyr->st_timer = PLR_ATK_SPD;
	if (state == RELOAD)
		plyr->st_timer = PLR_RLD_SPD;
}

void	pl_norm_state(t_cub *data, t_plyr *plyr)
{
	if (data->input.shoot)
	{
		if (plyr->ammo > 0)
		{
			plyr->ammo--;
			pew_pew(data);
			trigger_screen_shake(data, SCRSHK_INT_SHOOT, SCRSHK_DUR_SHOOT);
			pl_change_state(plyr, SHOOT);
		}
		data->input.shoot = false;
	}
	else if (data->input.reload && plyr->ammo < PLYR_MAX_AMMO)
		pl_change_state(plyr, RELOAD);
}

void	pl_reload_state(t_cub *data, t_plyr *plyr)
{
	plyr->st_timer -= data->d_time;
	if (plyr->st_timer <= 0)
	{
		plyr->ammo = PLYR_MAX_AMMO;
		pl_change_state(plyr, NORM);
	}
}

void	pl_shoot_state(t_cub *data, t_plyr *plyr)
{
	plyr->st_timer -= data->d_time;
	if (plyr->st_timer <= 0)
		pl_change_state(plyr, NORM);
	data->input.shoot = false;
}

void	pl_update(t_cub *data)
{
	t_plyr	*plyr;
	static	t_pl_state_func	states[3] = {pl_norm_state, pl_shoot_state,
		pl_reload_state};

	plyr = &data->gman.plyr;
	states[plyr->state](data, plyr);
}
