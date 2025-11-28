/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:59:01 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 23:51:18 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	render_crosshair(t_cub *data)
{
	t_v2i	c;
	int		gap;
	int		len;
	int		color;

	c.x = data->gfx.fr_bf.size.x / 2;
	c.y = data->gfx.fr_bf.size.y / 2;
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

void    draw_cross(t_img_d *frame, t_v2i icn_pos, t_v2i icn_size)
{
	t_v2i	start;
	t_v2i	end;
    t_v2i   center;
    int     thickness;
    int     half_len;

    center.x = icn_pos.x + (icn_size.x / 2); 
    center.y = icn_pos.y + (icn_size.y / 2); 
    thickness = icn_size.y / 4;
    half_len = icn_size.x / 2.5;
    start.x = center.x - half_len;
    start.y = center.y - (thickness / 2);
    end.x = center.x + half_len;
    end.y = center.y + (thickness / 2);
    drawrect_to_img(frame, start, end, 0xFF00FF00);
    start.x = center.x - (thickness / 2);
    start.y = center.y - half_len;
    end.x = center.x + (thickness / 2);
    end.y = center.y + half_len;
    drawrect_to_img(frame, start, end, 0xFF00FF00);
}

void	draw_health_bar(t_cub *data, t_img_d *frame, t_v2i icn_pos, t_v2i icn_size)
{
	t_v2i	bar_pos;
	t_v2i	bar_size;
	int		hp;
	
	hp = data->gman.plyr.hp;
	bar_pos.x = icn_pos.x + icn_size.x + 5;
	bar_pos.y = icn_pos.y + (icn_size.y / 2) - icn_size.y / 8;
	bar_size.x = ((float)hp / PLYR_MAX_HP) * (icn_size.x * 4);
	bar_size.y = icn_size.y / 4;
	drawrectrd_to_img(frame, bar_pos, bar_size, 0xFF00FF00);
}

void    hud_health(t_cub *data, t_img_d *frame, t_v2i pnl_pos, t_v2i pnl_size)
{
	t_v2i   icn_pos;
	t_v2i   icn_size;
	int     half_pnl_h;
	int     padding;

	icn_size.x = pnl_size.y / 3;
	icn_size.y = icn_size.x;
	half_pnl_h = pnl_size.y / 2; 
	padding = (half_pnl_h - icn_size.y) / 2;
	icn_pos.x = pnl_pos.x + padding;
	icn_pos.y = pnl_pos.y + padding; 
	drawrectrd_to_img(frame, icn_pos, icn_size, 0xFFFFFFFF);
	draw_cross(frame, icn_pos, icn_size);
	draw_health_bar(data, frame, icn_pos, icn_size);
}

void	draw_ammo_bar(t_cub *data, t_img_d *frame, t_v2i icn_pos, t_v2i icn_size)
{
	t_v2i	bar_pos;
	t_v2i	bar_size;
	int		ammo;
	
	ammo = data->gman.plyr.ammo;
	bar_pos.x = icn_pos.x + icn_size.x + 5;
	bar_pos.y = icn_pos.y + (icn_size.y / 2) - icn_size.y / 8;
	bar_size.x = ((float)ammo / PLYR_MAX_AMMO) * (icn_size.x * 4);
	bar_size.y = icn_size.y / 4;
	drawrectrd_to_img(frame, bar_pos, bar_size, 0xFFFF0000);
}

void    draw_bullet(t_img_d *frame, t_v2i icn_pos, t_v2i icn_size)
{
    t_v2i	start;
    t_v2i	end;
    t_v2i	center;
    int		tip_height;
	int		case_height;
	int		bullet_height;
    int		bullet_width;
    
    center.x = icn_pos.x + (icn_size.x / 2); 
    center.y = icn_pos.y + (icn_size.y / 2); 
    bullet_height = icn_size.y * 0.7;
    bullet_width = icn_size.x * 0.3;
    case_height = bullet_height * 0.6;
    start.x = center.x - (bullet_width / 2);
    end.x = center.x + (bullet_width / 2);
    start.y = center.y + (bullet_height / 2) - case_height;
    end.y = center.y + (bullet_height / 2);
    drawrect_to_img(frame, start, end, 0xFFCCAA00); 
    tip_height = bullet_height * 0.5;
    start.x = center.x - (bullet_width / 2);
    start.y = start.y - tip_height + 4;
    end.x = bullet_width;
    end.y = tip_height;
    drawrectrd_to_img(frame, start, end, 0xFFFFCC00);
}

void    hud_ammo(t_cub *data, t_img_d *frame, t_v2i pnl_pos, t_v2i pnl_size)
{
	t_v2i   icn_pos;
	t_v2i   icn_size;
	int     half_pnl_h;
	int     padding;

	icn_size.x = pnl_size.y / 3;
	icn_size.y = icn_size.x;
	half_pnl_h = pnl_size.y / 2; 
	padding = (half_pnl_h - icn_size.y) / 2;
	icn_pos.x = pnl_pos.x + padding;
	icn_pos.y = pnl_pos.y + pnl_size.y - icn_size.y - padding; 
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
	pnl_size.x = frame->size.x / 4;
	pnl_size.y = frame->size.y / 5;
	pnl_pos.x = 0;
	pnl_pos.y = frame->size.y - pnl_size.y;
	drawrectrd_to_img(frame, pnl_pos, pnl_size, 0xFF000066);
	hud_health(data, frame, pnl_pos, pnl_size);
	hud_ammo(data, frame, pnl_pos, pnl_size);
}
