/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:59:01 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 04:59:06 by luferna3         ###   ########.fr       */
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
