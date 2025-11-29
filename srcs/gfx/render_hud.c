/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:59:01 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 05:09:23 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	render_crosshair(t_cub *data)
{
	t_v2i	c;
	int		gap;
	int		len;
	int		color;

	c.x = data->gfx.fr_bf.size.x * 0.5;
	c.y = data->gfx.fr_bf.size.y * 0.5;
	gap = 3;
	len = 7;
	if (data->gman.plyr.target)
		color = 0x00FF0000;
	else
		color = 0x0000FF00;
	drawline_to_img(&data->gfx.fr_bf, (t_v2i){c.x - len, c.y},
		(t_v2i){c.x - gap, c.y},
		color);
	drawline_to_img(&data->gfx.fr_bf, (t_v2i){c.x + gap, c.y},
		(t_v2i){c.x + len, c.y},
		color);
	drawline_to_img(&data->gfx.fr_bf, (t_v2i){c.x, c.y - len},
		(t_v2i){c.x, c.y - gap},
		color);
	drawline_to_img(&data->gfx.fr_bf, (t_v2i){c.x, c.y + gap},
		(t_v2i){c.x, c.y + len},
		color);
}

void	draw_health_bar(t_cub *data, t_img_d *frame,
	t_v2i icn_pos, t_v2i icn_size)
{
	t_v2i	bar_pos;
	t_v2i	bar_size;
	int		hp;

	hp = data->gman.plyr.hp;
	bar_pos.x = icn_pos.x + icn_size.x + 5;
	bar_pos.y = icn_pos.y + (icn_size.y * 0.5) - icn_size.y * 0.125;
	bar_size.x = ((float)hp / PLYR_MAX_HP) * (icn_size.x * 4);
	bar_size.y = icn_size.y * 0.25;
	drawrectrd_to_img(frame, bar_pos, bar_size, 0xFF00FF00);
}

void	hud_health(t_cub *data, t_img_d *frame, t_v2i pnl_pos, t_v2i pnl_size)
{
	t_v2i	icn_pos;
	t_v2i	icn_size;
	int		half_pnl_h;
	int		padding;

	icn_size.x = pnl_size.y / 3;
	icn_size.y = icn_size.x;
	half_pnl_h = pnl_size.y * 0.5;
	padding = (half_pnl_h - icn_size.y) * 0.5;
	icn_pos.x = pnl_pos.x + padding;
	icn_pos.y = pnl_pos.y + (padding * 1.25);
	drawrectrd_to_img(frame, icn_pos, icn_size, 0xFFFFFFFF);
	draw_cross(frame, icn_pos, icn_size);
	draw_health_bar(data, frame, icn_pos, icn_size);
}

void	hud_ammo(t_cub *data, t_img_d *frame, t_v2i pnl_pos, t_v2i pnl_size)
{
	t_v2i	icn_pos;
	t_v2i	icn_size;
	int		half_pnl_h;
	int		padding;

	icn_size.x = pnl_size.y / 3;
	icn_size.y = icn_size.x;
	half_pnl_h = pnl_size.y * 0.5;
	padding = (half_pnl_h - icn_size.y) * 0.5;
	icn_pos.x = pnl_pos.x + padding;
	icn_pos.y = pnl_pos.y + pnl_size.y - icn_size.y - (padding * 1.25);
	drawrectrd_to_img(frame, icn_pos, icn_size, 0xFFFFFFFF);
	draw_bullet(frame, icn_pos, icn_size);
	if (data->gman.plyr.ammo)
		draw_ammo_bar(data, frame, icn_pos, icn_size);
}

void	hud_health_ammo(t_cub *data)
{
	t_img_d	*frame;
	t_v2i	pnl_size;
	t_v2i	pnl_pos;

	frame = &data->gfx.fr_bf;
	pnl_size.x = frame->size.x * 0.25;
	pnl_size.y = frame->size.y / 5;
	pnl_pos.x = 0;
	pnl_pos.y = frame->size.y - pnl_size.y;
	drawrectrd_to_img(frame, pnl_pos, pnl_size, 0xFF000066);
	hud_health(data, frame, pnl_pos, pnl_size);
	hud_ammo(data, frame, pnl_pos, pnl_size);
}
