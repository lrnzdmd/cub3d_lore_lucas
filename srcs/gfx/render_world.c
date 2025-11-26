/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 04:26:06 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/26 06:44:17 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_img_d	*world_texture_picker(t_cub *data, char cell, t_ray ray)
{
	if (cell == '2')
		return (&data->gfx.txt.wall.dr);
	if (ray.side)
	{
		if (ray.dir.y > 0)
			return (&data->gfx.txt.wall.n);
		else
			return (&data->gfx.txt.wall.s);
	}
	else
	{
		if (ray.dir.x > 0)
			return (&data->gfx.txt.wall.e);
		else
			return (&data->gfx.txt.wall.w);
	}
}

int	shade_texture(t_img_d *txt, t_v2i pos, t_ray ray)
{
	int	color;

	color = *(int *)calc_dest_addr(txt, pos);
	if (color == 0xFF00ff)
		return (color);
	if (ray.side && ray.dir.y > 0)
		return (darken_color(color, 40));
	else if (!ray.side)
		return (darken_color(color, 20));
	else
		return (color);
}

int	calc_texture_color(t_cub *data, t_ray *ray, t_v2i i)
{
	char	cell;
	t_v2i	out;
	t_img_d	*txt;
	double	y_offset;
	double	hit_frct;

	cell = data->gman.map.map[ray->map.y][ray->map.x];
	if (ray->side)
		hit_frct = (ray->st_pos.x + ray->p_dist * ray->dir.x);
	else
		hit_frct = (ray->st_pos.y + ray->p_dist * ray->dir.y);
	txt = world_texture_picker(data, cell, *ray);
	hit_frct -= floor(hit_frct);
	out.x = (int)(hit_frct * (double)(txt->size.x));
	if ((!ray->side && ray->dir.x < 0) || (ray->side && ray->dir.y > 0))
		out.x = txt->size.x - out.x - 1;
	if (ray->ln_hght == 0)
		ray->ln_hght = 1;
	y_offset = i.y * 256 - data->gfx.fr_bf.size.y * 128 + ray->ln_hght * 128;
	out.y = ((y_offset * txt->size.y) / ray->ln_hght) / 256;
	return (shade_texture(txt, out, *ray));
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
		if (data->gman.map.map[ray.map.y][ray.map.x] == '1')
			ray.hit = true;
		else if (data->gman.map.map[ray.map.y][ray.map.x] == '2')
			ray.hit = door_dda(&ray, data->gman.map.door_map);
	}
	if (!ray.door_hit)
	{
		if (ray.side)
			ray.p_dist = (ray.sd_dist.y - ray.d_dist.y);
		else
			ray.p_dist = (ray.sd_dist.x - ray.d_dist.x);
	}
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
		data->gfx.zbuffer[i.x] = ray.p_dist;
		i.y = ray.draw_st - 1;
		while (++i.y < ray.draw_end)
		{
			ray.color = calc_texture_color(data, &ray, i);
			*(int *)calc_dest_addr(&data->gfx.fr_bf, i) = ray.color;
		}
	}
}
