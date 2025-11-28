/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 05:20:12 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 22:09:49 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_h_line(t_img_d *img, t_v2i start, t_v2i end, int color)
{
	while (start.x != end.x)
	{
		*(unsigned int *)calc_dest_addr(img, start) = color;
		if (start.x <= end.x)
			start.x++;
		else
			start.x--;
	}
}

void	draw_v_line(t_img_d *img, t_v2i start, t_v2i end, int color)
{
	while (start.y != end.y)
	{
		*(unsigned int *)calc_dest_addr(img, start) = color;
		if (start.y <= end.y)
			start.y++;
		else
			start.y--;
	}
}
