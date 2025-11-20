/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:34:49 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/13 05:32:28 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	drawline_x_dom(t_img_d *img, t_v2i start, t_v2i end, int color);
static void	drawline_y_dom(t_img_d *img, t_v2i start, t_v2i end, int color);
static void	set_step_abs_delta(t_v2i *step, t_v2i *abs_d, t_v2i delta);

void	drawline_to_img(t_img_d *img, t_v2i start, t_v2i end, int color)
{
	t_v2i	delta;

	start.x = ft_clamp_i(start.x, 0, img->size.x);
	start.y = ft_clamp_i(start.y, 0, img->size.y);
	end.x = ft_clamp_i(end.x, 0, img->size.x);
	end.y = ft_clamp_i(end.y, 0, img->size.y);
	delta = ft_subtr_v2i(end, start);
	if (start.x == end.x)
		draw_v_line(img, start, end, color);
	else if (start.y == end.y)
		draw_h_line(img, start, end, color);
	else if (abs(delta.x) > abs(delta.y))
		drawline_x_dom(img, start, end, color);
	else
		drawline_y_dom(img, start, end, color);
}

void	drawrect_to_img(t_img_d	*img, t_v2i top_l, t_v2i bot_r, int color)
{
	top_l.x = ft_clamp_i(top_l.x, 0, img->size.x);
	top_l.y = ft_clamp_i(top_l.y, 0, img->size.y);
	bot_r.x = ft_clamp_i(bot_r.x, 0, img->size.x);
	bot_r.y = ft_clamp_i(bot_r.y, 0, img->size.y);
	while (top_l.y != bot_r.y)
	{
		drawline_to_img(img, top_l, (t_v2i){bot_r.x, top_l.y}, color);
		if (top_l.y < bot_r.y)
			top_l.y++;
		else
			top_l.y--;
	}
	drawline_to_img(img, top_l, (t_v2i){bot_r.x, top_l.y}, color);
}

static void	drawline_x_dom(t_img_d *img, t_v2i start, t_v2i end, int color)
{
	t_v2i	dir;
	t_v2i	delta;
	t_v2i	abs_d;
	t_v2i	step;
	int		err[2];

	delta = ft_subtr_v2i(end, start);
	set_step_abs_delta(&step, &abs_d, delta);
	err[0] = 2 * abs_d.y - abs_d.x;
	dir = start;
	while (1)
	{
		*(unsigned int *)calc_dest_addr(img, dir) = color;
		if (dir.x == end.x)
			break ;
		err[1] = err[0];
		dir.x += step.x;
		err[0] += 2 * abs_d.y;
		if (err[1] > 0)
		{
			dir.y += step.y;
			err[0] -= 2 * abs_d.x;
		}
	}
}

static void	drawline_y_dom(t_img_d *img, t_v2i start, t_v2i end, int color)
{
	t_v2i	dir;
	t_v2i	delta;
	t_v2i	abs_d;
	t_v2i	step;
	int		err[2];

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	set_step_abs_delta(&step, &abs_d, delta);
	err[0] = 2 * abs_d.x - abs_d.y;
	dir = start;
	while (1)
	{
		*(unsigned int *)calc_dest_addr(img, dir) = color;
		if (dir.y == end.y)
			break ;
		err[1] = err[0];
		dir.y += step.y;
		err[0] += 2 * abs_d.x;
		if (err[1] > 0)
		{
			dir.x += step.x;
			err[0] -= 2 * abs_d.y;
		}
	}
}

static void	set_step_abs_delta(t_v2i *step, t_v2i *abs_d, t_v2i delta)
{
	if (delta.x > 0)
		step->x = 1;
	else
		step->x = -1;
	if (delta.y > 0)
		step->y = 1;
	else
		step->y = -1;
	abs_d->x = abs(delta.x);
	abs_d->y = abs(delta.y);
}
