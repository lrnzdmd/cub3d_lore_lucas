/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:46:43 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/20 00:18:42 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_v2d	ft_set_v2d(double x, double y)
{
	t_v2d	out;

	out.x = x;
	out.y = y;
	return (out);
}

t_v2d	ft_sum_v2d(t_v2d v1, t_v2d v2)
{
	t_v2d	out;

	out.x = v1.x + v2.x;
	out.y = v1.y + v2.y;
	return (out);
}

t_v2d	ft_subtr_v2d(t_v2d v1, t_v2d v2)
{
	t_v2d	out;

	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
	return (out);
}

double	ft_length_v2d(t_v2d	vec)
{
	return (ft_sqrt((vec.x * vec.x) + (vec.y * vec.y)));
}

double	ft_distance_sq_v2d(t_v2d v1, t_v2d v2)
{
	t_v2d	d;

	d.x = v2.x - v1.x;
	d.y = v2.y - v1.y;
	return ((d.x * d.x) + (d.y * d.y));
}
