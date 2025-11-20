/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:54:37 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/13 05:52:15 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_clr	set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	t_clr	clr;

	clr.c.r = r;
	clr.c.g = g;
	clr.c.b = b;
	clr.c.a = a;
	return (clr);
}

int	darken_color(int color, int amount)
{
	t_clr	out;

	out.color = color;
	if (out.c.r - amount < 0)
		out.c.r = 0;
	else
		out.c.r -= amount;
	if (out.c.g - amount < 0)
		out.c.g = 0;
	else
		out.c.g -= amount;
	if (out.c.b - amount < 0)
		out.c.b = 0;
	else
		out.c.b -= amount;
	return (out.color);
}
