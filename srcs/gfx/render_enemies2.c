/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 05:30:17 by luferna3          #+#    #+#             */
/*   Updated: 2025/11/25 05:53:01 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	render_sprite(t_cub *data, t_ent *enemy, t_ray_s ray)
{
	int		proy;
	t_v2i	i;
	t_v2i	txt_p;

	order_sprites(data);
	i.x = ray.draw_st.x - 1;
	while (++i.x < ray.draw_end.x)
	{
		txt_p.x = (256 * (i.x - (-ray.size / 2 + ray.scr_x))
				* enemy->sprt->size.x / ray.size) / 256;
		if (ray.transf.y > 0 && i.x > 0 && i.x < data->gfx.fr_bf.size.x
			&& ray.transf.y < data->gfx.zbuffer[i.x])
		{
			i.y = ray.draw_st.y - 1;
			while (++i.y < ray.draw_end.y)
			{
				proy = (i.y) * 256 - data->gfx.fr_bf.size.y * 128 + ray.size
					* 128;
				txt_p.y = ((proy * enemy->sprt->size.y) / ray.size) / 256;
				ray.color = get_sprite_pixel(enemy->sprt, txt_p);
				if ((ray.color & 0x00FFFFFF) != 0xFF00FF)
					*(int *)calc_dest_addr(&data->gfx.fr_bf, i) = ray.color;
			}
		}
	}
}

void	init_enemy_data(t_cub **data, t_ray_s *ray, t_plyr *plyr)
{
	(*data)->gman.plyr.target = NULL;
	(*data)->gman.plyr.tgt_dist = __DBL_MAX__;
	(*plyr) = (*data)->gman.plyr;
	ray->inv_det = 1.0
		/ (plyr->plane.x * plyr->dir.y - plyr->plane.y * plyr->dir.x);
}

void	render_enemies(t_cub *data)
{
	int		i;
	t_ent	*enemy;
	t_ray_s	ray;
	t_plyr	plyr;

	i = -1;
	init_enemy_data(&data, &ray, &plyr);
	while (++i < data->gman.enemies_n)
	{
		enemy = &data->gman.enemies[i];
		init_sprite_ray(data, enemy, &ray);
		if (enemy->data.state != DEAD && ray.transf.y > 0)
		{
			if (is_shootable(data, ray))
			{
				if (ray.transf.y < data->gman.plyr.tgt_dist)
				{
					data->gman.plyr.tgt_dist = ray.transf.y;
					data->gman.plyr.target = enemy;
				}
			}
		}
		render_sprite(data, &data->gman.enemies[i], ray);
	}
}
