/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 05:51:59 by luferna3          #+#    #+#             */
/*   Updated: 2025/11/25 05:59:05 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// bool	door_dda(t_ray *ray, t_door	***doors)
// {
// 	t_door	*door;
// 	double	p_pos;
// 	double	dir;
// 	int		map;

// 	door = doors[ray->map.y][ray->map.x];
// 	if (!ray->side != (door->hor == V))
// 		return (false);
// 	if (!ray->side)
// 	{
// 		p_pos = ray->st_pos.x;
// 		dir = ray->dir.x;
// 		map = ray->map.x;
// 		ray->wl_dist = ray->sd_dist.y; 
// 	}
// 	else
// 	{
// 		p_pos = ray->st_pos.y;
// 		dir = ray->dir.y;
// 		map = ray->map.y;
// 		ray->wl_dist = ray->sd_dist.x; 
// 	}
// 	ray->dr_dist = (map + 0.5 - p_pos) / dir;
// 	if (ray->dr_dist < ray->wl_dist)
// 	{
// 		ray->p_dist = ray->dr_dist;
// 		ray->door_hit = true;
// 		return (true);
// 	}
// 	return (false);
// }

static void	set_door_params(t_ray *ray, double *p_pos, double *dir, int *map)
{
	if (!ray->side)
	{
		*p_pos = ray->st_pos.x;
		*dir = ray->dir.x;
		*map = ray->map.x;
		ray->wl_dist = ray->sd_dist.y;
	}
	else
	{
		*p_pos = ray->st_pos.y;
		*dir = ray->dir.y;
		*map = ray->map.y;
		ray->wl_dist = ray->sd_dist.x;
	}
}

bool	door_dda(t_ray *ray, t_door ***doors)
{
	t_door	*door;
	double	p_pos;
	double	dir;
	int		map;

	door = doors[ray->map.y][ray->map.x];
	if (!ray->side != (door->hor == V))
		return (false);
	set_door_params(ray, &p_pos, &dir, &map);
	ray->dr_dist = (map + 0.5 - p_pos) / dir;
	if (ray->dr_dist >= ray->wl_dist)
		return (false);
	ray->p_dist = ray->dr_dist;
	ray->door_hit = true;
	return (true);
}
