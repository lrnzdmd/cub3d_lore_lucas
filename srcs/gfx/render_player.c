/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:36:22 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 02:55:42 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	player_animator(t_cub *data)
{
	t_anim	*anim;
	t_plyr	*plyr;

	plyr = &data->gman.plyr;
	anim = plyr->anim;
	if (!anim || !anim->frame)
		return ;
	plyr->anim_timer += data->d_time;
	if (plyr->anim_timer >= anim->speed)
	{
		plyr->anim_timer = 0;
		if (anim->loop)
			plyr->anim_frm = (plyr->anim_frm + 1) % anim->frm_n;
		else
		{
			if (plyr->anim_frm < anim->frm_n - 1)
				plyr->anim_frm++;
		}
	}
	plyr->sprt = &anim->frame[plyr->anim_frm];
}

void	set_pl_animation(t_plyr *plyr, t_anim *anim)
{
	if (plyr->anim == anim)
		return ;
	plyr->anim = anim;
	plyr->anim_frm = 0;
	plyr->anim_timer = 0;
}

static t_v2i	calc_gun_bounds(t_cub *data, t_v2i *start, t_v2i *end)
{
	t_v2i	size;

	size.x = data->gfx.fr_bf.size.y * 0.6;
	size.y = size.x;
	start->x = data->gfx.fr_bf.size.x * 0.5;
	start->y = data->gfx.fr_bf.size.y - size.y;
	end->x = start->x + size.x;
	end->y = start->y + size.y;
	return (size);
}

static void	draw_gun_pixel(t_cub *data, t_v2i i, t_v2i start, t_v2i size)
{
	t_v2i	txt_cd;
	t_img_d	*sprite;
	int		color;

	sprite = data->gman.plyr.sprt;
	txt_cd.x = ((i.x - start.x) * sprite->size.x) / size.x;
	txt_cd.y = ((i.y - start.y) * sprite->size.y) / size.y;
	color = get_sprite_pixel(sprite, txt_cd);
	if ((color & 0x00FFFFFF) != 0xFF00FF)
		*(int *)calc_dest_addr(&data->gfx.fr_bf, i) = color;
}

void	render_player(t_cub *data)
{
	t_v2i	i;
	t_v2i	start;
	t_v2i	end;
	t_v2i	size;

	size = calc_gun_bounds(data, &start, &end);
	i.y = start.y - 1;
	while (++i.y < end.y)
	{
		i.x = start.x - 1;
		while (++i.x < end.x)
			draw_gun_pixel(data, i, start, size);
	}
}

// void	render_player(t_cub *data)
// {
// 	t_v2i	i;
// 	t_v2i	start;
// 	t_v2i	txt_cd;
// 	t_v2i	end;
// 	int		color;
// 	int		size;

// 	size = data->gfx.fr_bf.size.y / 2.5;
// 	start.x = (data->gfx.fr_bf.size.x / 2);
// 	start.y = (data->gfx.fr_bf.size.y - size);
// 	end.x = start.x + size;
// 	end.y = start.y + size;
// 	i.y = start.y - 1;
// 	while (++i.y < end.y)
// 	{
// 		i.x = start.x - 1;
// 		while (++i.x < end.x)
// 		{
// 			txt_cd.x = ((i.x - start.x) * data->gfx.txt.sprts.gun[0].size.x)
// 				/ size;
// 			txt_cd.y = ((i.y - start.y) * data->gfx.txt.sprts.gun[0].size.y)
// 				/ size;
// 			color = get_sprite_pixel(data->gman.plyr.sprt, txt_cd);
// 			if ((color & 0x00FFFFFF) != 0xFF00FF)
// 				*(int *)calc_dest_addr(&data->gfx.fr_bf, i) = color;
// 		}
// 	}
// }
