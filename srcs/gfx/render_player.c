/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:36:22 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/23 22:13:43 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
			color = get_sprite_pixel(&data->gfx.txt.sprts.gun[0], txt_cd);
			if ((color & 0x00FFFFFF) != 0xFF00FF)
				*(int *)calc_dest_addr(&data->gfx.fr_bf, i) = color;
		}
	}
}