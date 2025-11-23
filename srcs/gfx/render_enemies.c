/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:44:28 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/24 00:37:34 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_sprite_ray(t_cub *data, t_ent *enemy, t_ray_s *ray)
{
	t_plyr	plyr;

	plyr = data->gman.plyr;
	ray->rel_pos.x = enemy->pos.x - plyr.pos.x;
	ray->rel_pos.y = enemy->pos.y - plyr.pos.y;
	ray->transf.x = ray->inv_det * (plyr.dir.y
		* ray->rel_pos.x - plyr.dir.x * ray->rel_pos.y);
	ray->transf.y = ray->inv_det * (-plyr.plane.y
		* ray->rel_pos.x + plyr.plane.x * ray->rel_pos.y);
	ray->scr_x = (data->gfx.fr_bf.size.x / 2)
		* (1 + (ray->transf.x / ray->transf.y));
	ray->size = fabs(floor(data->gfx.fr_bf.size.y / ray->transf.y));
	ray->draw_st.y = -ray->size / 2 + data->gfx.fr_bf.size.y / 2;
	if (ray->draw_st.y < 0)
		ray->draw_st.y = 0;
	ray->draw_end.y = ray->size / 2 + data->gfx.fr_bf.size.y / 2;
	if (ray->draw_end.y >= data->gfx.fr_bf.size.y)
		ray->draw_end.y = data->gfx.fr_bf.size.y - 1;
	ray->draw_st.x = -ray->size / 2 + ray->scr_x;
	if (ray->draw_st.x < 0)
		ray->draw_st.x = 0;
	ray->draw_end.x = ray->size / 2 + ray->scr_x;
	if (ray->draw_end.x >= data->gfx.fr_bf.size.x)
		ray->draw_end.x = data->gfx.fr_bf.size.x - 1;
}

int get_sprite_pixel(t_img_d *txt, t_v2i pos)
{
    int color;
    
    if (pos.x < 0 || pos.x >= txt->size.x || pos.y < 0 || pos.y >= txt->size.y)
        return (0xFF00FF);
    color = *(int *)calc_dest_addr(txt, pos);
    return (color);
}

bool	is_shootable(t_cub *data, t_ray_s ray)
{
	int		center;
	int		aim;

	center = data->gfx.fr_bf.size.x / 2;
	aim = (data->gfx.fr_bf.size.x * PLR_AIM_SIZE);
	if (ray.scr_x >= center - aim && ray.scr_x <= center + aim)
		return (true);
	else
		return (false);
}

void	render_sprite(t_cub *data, t_ent *enemy, t_ray_s ray)
{
	int		proy;
	t_v2i	i;
	t_v2i	txt_p;

	i.x = ray.draw_st.x - 1;
	while (++i.x < ray.draw_end.x)
	{
		txt_p.x = (256 * (i.x - (-ray.size / 2 + ray.scr_x))
			* enemy->sprt->size.x / ray.size) / 256;
		if (ray.transf.y > 0 && i.x > 0 && i.x < data->gfx.fr_bf.size.x && ray.transf.y < data->gfx.zbuffer[i.x])
		{
			i.y = ray.draw_st.y - 1;
			while (++i.y < ray.draw_end.y)
			{
				proy =  (i.y) * 256 - data->gfx.fr_bf.size.y * 128 + ray.size * 128;
				txt_p.y = ((proy * enemy->sprt->size.y) / ray.size) / 256;
				ray.color = get_sprite_pixel(enemy->sprt, txt_p);
				if ((ray.color & 0x00FFFFFF) != 0xFF00FF)
					*(int *)calc_dest_addr(&data->gfx.fr_bf, i) = ray.color;
			}
		}
	}
}

void	render_enemies(t_cub *data)
{
	int		i;
	t_ent	*enemy;
	t_ray_s	ray;
	t_plyr	plyr;

	i = -1;
	data->gman.plyr.target = NULL;
	data->gman.plyr.tgt_dist = __DBL_MAX__;
	plyr = data->gman.plyr;
	ray.inv_det = 1.0 / (plyr.plane.x * plyr.dir.y - plyr.plane.y * plyr.dir.x);
	while (++i < data->gman.enemies_n)
	{
		enemy = &data->gman.enemies[i];
		init_sprite_ray(data, enemy, &ray);
		if (enemy->data.state != DEAD && ray.transf.y > 0.5)
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
