/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:46:21 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 03:43:27 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_game(t_cub *data)
{
	draw_background(data);
	render_world(data);
	render_enemies(data);
	render_player(data);
	render_crosshair(data);
	hud_health_ammo(data);
	if (data->input.map_toggle)
	{
		draw_minimap(data);
		draw_player_minimap(data);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_w,
		data->gfx.fr_bf.img_p, 0, 0);
}

void	draw_background(t_cub	*data)
{
	int		i;
	int		total_pix;
	int		*addr;
	t_img_d	*frm;

	frm = &data->gfx.fr_bf;
	addr = (int *)frm->addr;
	total_pix = (frm->size.x * frm->size.y);
	i = -1;
	while (++i < (total_pix * 0.5) - (frm->size.x * -data->gman.plyr.pitch))
		addr[i] = data->gfx.ceil_c.color;
	while (i < total_pix)
		addr[i++] = data->gfx.grnd_c.color;
}
