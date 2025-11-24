/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:36:22 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/24 02:21:34 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	player_animator(t_cub *data)
{
	t_plyr	*plyr;

	plyr = &data->gman.plyr;
	if (plyr->state == NORM)
	{
		plyr->sprt = &data->gfx.txt.sprts.gun[0];
		plyr->anim_timer = 0;
		return ;
	}
	plyr->anim_timer += data->d_time;
	if (plyr->anim_timer >= ANM_SPD_SHOOT)
	{
		plyr->state = NORM;
		return ;
	}
	if (plyr->anim_timer < (ANM_SPD_SHOOT * 0.50))
        plyr->sprt = &data->gfx.txt.sprts.gun[1];
    else
        plyr->sprt = &data->gfx.txt.sprts.gun[0];
}

void	render_player(t_cub *data)
{
	t_v2i	i;
	t_v2i	start;
	t_v2i	txt_cd;
	t_v2i	end;
	int		color;
	int		size;

	size = data->gfx.fr_bf.size.y / 2.5;
	start.x = (data->gfx.fr_bf.size.x / 2);
	start.y = (data->gfx.fr_bf.size.y - size);
	end.x = start.x + size;
	end.y = start.y + size;
	i.y = start.y - 1;
	while (++i.y < end.y)
	{
		i.x = start.x - 1;
		while (++i.x < end.x)
		{
			txt_cd.x = ((i.x - start.x) * data->gfx.txt.sprts.gun[0].size.x) / size;
			txt_cd.y = ((i.y - start.y) * data->gfx.txt.sprts.gun[0].size.y) / size;
			color = get_sprite_pixel(data->gman.plyr.sprt, txt_cd);
			if ((color & 0x00FFFFFF) != 0xFF00FF)
				*(int *)calc_dest_addr(&data->gfx.fr_bf, i) = color;
		}
	}
}