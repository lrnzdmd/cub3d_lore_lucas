/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 06:44:28 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 02:58:04 by lde-medi         ###   ########.fr       */
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
	ray->draw_st.y = -ray->size * 0.5 + data->gfx.fr_bf.size.y * 0.5 + plyr.pitch;
	if (ray->draw_st.y < 0)
		ray->draw_st.y = 0;
	ray->draw_end.y = ray->size * 0.5 + data->gfx.fr_bf.size.y * 0.5 + plyr.pitch;
	if (ray->draw_end.y >= data->gfx.fr_bf.size.y)
		ray->draw_end.y = data->gfx.fr_bf.size.y - 1;
	ray->draw_st.x = -ray->size * 0.5 + ray->scr_x;
	if (ray->draw_st.x < 0)
		ray->draw_st.x = 0;
	ray->draw_end.x = ray->size * 0.5 + ray->scr_x;
	if (ray->draw_end.x >= data->gfx.fr_bf.size.x)
		ray->draw_end.x = data->gfx.fr_bf.size.x - 1;
}

int	get_sprite_pixel(t_img_d *txt, t_v2i pos)
{
	int	color;

	if (pos.x < 0 || pos.x >= txt->size.x || pos.y < 0 || pos.y >= txt->size.y)
		return (0xFF00FF);
	color = *(int *)calc_dest_addr(txt, pos);
	return (color);
}

bool	is_shootable(t_cub *data, t_ray_s ray)
{
	int			sp_cnt;
	t_v2i		center;
	bool		hit_x;
	bool		hit_y;
	t_v2i		aim;

	sp_cnt = (int)round(ray.scr_x);
	if (ray.transf.y <= 0 || sp_cnt < 0
		|| sp_cnt >= data->gfx.fr_bf.size.x
		|| ray.transf.y >= data->gfx.zbuffer[sp_cnt])
		return (false);
	center.x = data->gfx.fr_bf.size.x / 2;
	center.y = data->gfx.fr_bf.size.y / 2;
	aim.x = (ray.size * PLR_AIM_SIZE) / 2;
	aim.y = (ray.size * 0.1);
	hit_x = (center.x >= ((ray.scr_x - aim.x))
			&& center.x <= (ray.scr_x + aim.x));
	hit_y = (center.y >= (ray.draw_st.y - aim.y)
			&& center.y <= (ray.draw_end.y + aim.y));
	return (hit_x && hit_y);
}

static void	calc_sprite_distances(t_cub *data)
{
	int		i;
	t_ent	*sprts;

	sprts = data->gman.enemies;
	i = -1;
	while (++i < data->gman.enemies_n)
		sprts[i].pl_dist = ft_distance_sq_v2d(sprts[i].pos,
				data->gman.plyr.pos);
}

void	order_sprites(t_cub *data)
{
	int		i;
	bool	sort;
	t_ent	tmp;
	t_ent	*sprts;

	calc_sprite_distances(data);
	sprts = data->gman.enemies;
	sort = false;
	while (!sort)
	{
		sort = true;
		i = -1;
		while (++i < data->gman.enemies_n - 1)
		{
			if (sprts[i].pl_dist < sprts[i + 1].pl_dist)
			{
				tmp = sprts[i];
				sprts[i] = sprts[i + 1];
				sprts[i + 1] = tmp;
				sort = false;
			}
		}
	}
}

// void	order_sprites(t_cub *data)
// {
// 	int			i;
// 	bool		sort;
// 	t_ent		tmp;
// 	t_ent		*sprts;

// 	sprts = data->gman.enemies;
// 	i = -1;
// 	while (++i < data->gman.enemies_n)
// 		sprts[i].pl_dist = ft_distance_sq_v2d(sprts[i].pos,
// 				data->gman.plyr.pos);
// 	sort = false;
// 	while (!sort)
// 	{
// 		sort = true;
// 		i = -1;
// 		while (++i < data->gman.enemies_n - 1)
// 		{
// 			if (sprts[i].pl_dist < sprts[i + 1].pl_dist)
// 			{
// 				tmp = sprts[i];
// 				sprts[i] = sprts[i + 1];
// 				sprts[i + 1] = tmp;
// 				sort = false;
// 			}
// 		}
// 	}
// }