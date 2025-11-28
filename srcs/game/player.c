/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:14:40 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 00:56:59 by lde-medi         ###   ########.fr       */
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
		pl_change_state(plyr, SHOOT);
	if (data->input.reload)
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
	if (!plyr->ammo)
		return ;
	if (data->input.shoot)
	{
		trigger_screen_shake(data, SCRSHK_INT_SHOOT, SCRSHK_DUR_SHOOT);
		plyr->ammo--;
		pew_pew(data);
	}
	plyr->st_timer -= data->d_time;
	if (plyr->st_timer <= 0)
		pl_change_state(plyr, NORM);
	data->input.shoot = false;
}

void	pl_update(t_cub *data)
{
	t_plyr *plyr;

	plyr = &data->gman.plyr;
	if (plyr->state == NORM)
		pl_norm_state(data, plyr);
	else if (plyr->state == SHOOT)
		pl_shoot_state(data, plyr);
	else
		pl_reload_state(data, plyr);
}
