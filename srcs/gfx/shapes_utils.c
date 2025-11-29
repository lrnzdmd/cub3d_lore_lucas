/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 05:20:12 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 16:34:37 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_ammo_bar(t_cub *data, t_img_d *frame,
	t_v2i icn_pos, t_v2i icn_size)
{
	t_v2i	bar_pos;
	t_v2i	bar_size;
	int		space;
	int		ammo;

	ammo = data->gman.plyr.ammo;
	space = ((data->gfx.fr_bf.size.x * 0.25) - (icn_size.x * 1.8));
	bar_pos.x = icn_pos.x + icn_size.x + 5;
	bar_pos.y = icn_pos.y + (icn_size.y * 0.5) - icn_size.y * 0.125;
	bar_size.x = ((float)ammo / PLYR_MAX_AMMO) * space;
	bar_size.y = icn_size.y * 0.25;
	drawrectrd_to_img(frame, bar_pos, bar_size, 0xFFFF0000);
}

void	drawrectrd_to_img(t_img_d *img, t_v2i pos, t_v2i size, int color)
{
	int		r;
	t_v2i	tl;
	t_v2i	br;

	r = 4;
	if (size.x < r * 2)
		r = size.x * 0.5;
	if (size.y < r * 2)
		r = size.y * 0.5;
	tl = (t_v2i){pos.x, pos.y + r};
	br = (t_v2i){pos.x + size.x, pos.y + size.y - r};
	drawrect_to_img(img, tl, br, color);
	tl = (t_v2i){pos.x + r, pos.y};
	br = (t_v2i){pos.x + size.x - r, pos.y + size.y};
	drawrect_to_img(img, tl, br, color);
	drawcircle_to_img(img, (t_v2i){pos.x + r, pos.y + r}, r, color);
	drawcircle_to_img(img, (t_v2i){pos.x + size.x - r - 1, pos.y + r},
		r, color);
	drawcircle_to_img(img, (t_v2i){pos.x + r, pos.y + size.y - r - 1},
		r, color);
	drawcircle_to_img(img, (t_v2i){pos.x + size.x - r - 1,
		pos.y + size.y - r - 1}, r, color);
}

void	drawcircle_to_img(t_img_d *img, t_v2i center, int r, int color)
{
	t_v2i	i;
	int		dist_sq;

	i.y = -r - 1;
	while (++i.y <= r)
	{
		i.x = -r - 1;
		while (++i.x <= r)
		{
			dist_sq = (i.x * i.x) + (i.y * i.y);
			if (dist_sq <= (r * r))
				*(unsigned int *)calc_dest_addr(img,
					(t_v2i){center.x + i.x, center.y + i.y}) = color;
		}
	}
}

void	draw_h_line(t_img_d *img, t_v2i start, t_v2i end, int color)
{
	while (start.x != end.x)
	{
		*(unsigned int *)calc_dest_addr(img, start) = color;
		if (start.x < end.x)
			start.x++;
		else
			start.x--;
	}
}

void	draw_v_line(t_img_d *img, t_v2i start, t_v2i end, int color)
{
	while (start.y != end.y)
	{
		*(unsigned int *)calc_dest_addr(img, start) = color;
		if (start.y < end.y)
			start.y++;
		else
			start.y--;
	}
}
