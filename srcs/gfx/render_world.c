/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 04:26:06 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/22 06:12:51 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_ray_dir(t_cub *data, t_ray *ray, int x)
{
	t_plyr	plyr;

	plyr = data->gman.plyr;
	ray->st_pos = plyr.pos;
	ray->end_pos = ray->st_pos;
	ray->cam_x = 2 * x / (double)data->gfx.fr_bf.size.x - 1;
	ray->dir.x = plyr.dir.x + plyr.plane.x * ray->cam_x;
	ray->dir.y = plyr.dir.y + plyr.plane.y * ray->cam_x;
}

void	init_ray_d_dist(t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->d_dist.x = 1e30;
	else
		ray->d_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->d_dist.y = 1e30;
	else
		ray->d_dist.y = fabs(1 / ray->dir.y);
}

void	init_ray_sd_dist(t_ray *ray)
{
	ray->map.x = (int)ray->end_pos.x;
	ray->map.y = (int)ray->end_pos.y;
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->sd_dist.x = (ray->end_pos.x - ray->map.x) * ray->d_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sd_dist.x = (ray->map.x + 1.0 - ray->end_pos.x) * ray->d_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->sd_dist.y = (ray->end_pos.y - ray->map.y) * ray->d_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sd_dist.y = (ray->map.y + 1.0 - ray->end_pos.y) * ray->d_dist.y;
	}
}

void	ray_dda(t_ray *ray)
{
	if (ray->sd_dist.x < ray->sd_dist.y)
	{
		ray->sd_dist.x += ray->d_dist.x;
		ray->map.x += ray->step.x;
		ray->side = false;
	}
	else
	{
		ray->sd_dist.y += ray->d_dist.y;
		ray->map.y += ray->step.y;
		ray->side = true;
	}
}

void	init_ray(t_cub *data, t_ray *ray, int x)
{
	ray->hit = false;
	ray->door_hit = false;
	init_ray_dir(data, ray, x);
	init_ray_d_dist(ray);
	init_ray_sd_dist(ray);
}

t_ray	cast_ray(t_cub *data, int x)
{
	t_ray	ray;

	init_ray(data, &ray, x);
	while (!ray.hit)
	{
		ray_dda(&ray);
		if (ray.map.x < 0 || ray.map.y < 0
			|| ray.map.x > data->gman.map.size.x
			|| ray.map.y > data->gman.map.size.y)
			break ;
		if (data->gman.map.map[ray.map.y][ray.map.x] != '0')
			ray.hit = true;
	}
	if (ray.side)
		ray.p_dist = (ray.sd_dist.y - ray.d_dist.y);
	else
		ray.p_dist = (ray.sd_dist.x - ray.d_dist.x);
	return (ray);
}

void	render_world(t_cub *data)
{
	t_v2i	i;
	t_ray	ray;

	i.x = -1;
	while (++i.x < data->gfx.fr_bf.size.x)
	{
		ray = cast_ray(data, i.x);
		ray.ln_hght = (int)(data->gfx.fr_bf.size.y / ray.p_dist);
		ray.draw_st = -ray.ln_hght / 2 + data->gfx.fr_bf.size.y / 2;
		if (ray.draw_st < 0)
			ray.draw_st = 0;
		ray.draw_end = ray.ln_hght / 2 + data->gfx.fr_bf.size.y / 2;
		if (ray.draw_end >= data->gfx.fr_bf.size.y)
			ray.draw_end = data->gfx.fr_bf.size.y - 1;
		draw_v_line(&data->gfx.fr_bf, (t_v2i){i.x, ray.draw_st},
			(t_v2i){i.x, ray.draw_end}, 0x00ff0000);
	}
}
