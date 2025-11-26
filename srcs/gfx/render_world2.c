/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 05:53:55 by luferna3          #+#    #+#             */
/*   Updated: 2025/11/26 07:10:56 by luferna3         ###   ########.fr       */
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
	double	camera_x;

	camera_x = 2.0 * x / (double)data->gfx.fr_bf.size.x - 1.0;	
	ray->dir.x = data->gman.plyr.dir.x + data->gman.plyr.plane.x * camera_x;
	ray->dir.y = data->gman.plyr.dir.y + data->gman.plyr.plane.y * camera_x;
	ray->hit = false;
	ray->door_hit = false;
	init_ray_dir(data, ray, x);
	init_ray_d_dist(ray);
	init_ray_sd_dist(ray);
}
