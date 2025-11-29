/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:54:37 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 05:05:41 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_clr	set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_clr	clr;

	clr.c.r = r;
	clr.c.g = g;
	clr.c.b = b;
	clr.c.a = a;
	return (clr);
}

int	darken_color(int color, int amount)
{
	t_clr	out;

	out.color = color;
	if (out.c.r - amount < 0)
		out.c.r = 0;
	else
		out.c.r -= amount;
	if (out.c.g - amount < 0)
		out.c.g = 0;
	else
		out.c.g -= amount;
	if (out.c.b - amount < 0)
		out.c.b = 0;
	else
		out.c.b -= amount;
	return (out.color);
}

void	draw_map_tile(t_cub *data, t_img_d	*img, t_v2i map)
{
	t_v2i	pos;
	int		tile_size;

	tile_size = data->gman.map.tile_size;
	pos = map_to_pixel_coords(data->gman.map, (t_v2d){map.x, map.y});
	drawrect_to_img(img, pos,
		(t_v2i){pos.x + tile_size, pos.y + tile_size}, MAP_CLR_WL);
}

void	draw_bullet(t_img_d *frame, t_v2i icn_pos, t_v2i icn_size)
{
	t_v2i	start;
	t_v2i	end;
	t_v2i	center;
	int		bullet_height;
	int		bullet_width;

	center.x = icn_pos.x + (icn_size.x * 0.5);
	center.y = icn_pos.y + (icn_size.y * 0.5);
	bullet_height = icn_size.y * 0.7;
	bullet_width = icn_size.x * 0.3;
	start.x = center.x - (bullet_width * 0.5);
	end.x = center.x + (bullet_width * 0.5);
	start.y = center.y + (bullet_height * 0.5) - (bullet_height * 0.6);
	end.y = center.y + (bullet_height * 0.5);
	drawrect_to_img(frame, start, end, 0xFFCCAA00);
	start.x = center.x - (bullet_width * 0.5);
	start.y = start.y - (bullet_height * 0.5) + 4;
	end.x = bullet_width;
	end.y = bullet_height * 0.5;
	drawrectrd_to_img(frame, start, end, 0xFFFFCC00);
}

void	draw_cross(t_img_d *frame, t_v2i icn_pos, t_v2i icn_size)
{
	t_v2i	start;
	t_v2i	end;
	t_v2i	center;
	int		thickness;
	int		half_len;

	center.x = icn_pos.x + (icn_size.x * 0.5);
	center.y = icn_pos.y + (icn_size.y * 0.5);
	thickness = icn_size.y * 0.25;
	half_len = icn_size.x * 0.4;
	start.x = center.x - half_len;
	start.y = center.y - (thickness * 0.5);
	end.x = center.x + half_len;
	end.y = center.y + (thickness * 0.5);
	drawrect_to_img(frame, start, end, 0xFF00FF00);
	start.x = center.x - (thickness * 0.5);
	start.y = center.y - half_len;
	end.x = center.x + (thickness * 0.5);
	end.y = center.y + half_len;
	drawrect_to_img(frame, start, end, 0xFF00FF00);
}
