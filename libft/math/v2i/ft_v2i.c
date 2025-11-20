/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v2i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:01:53 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/12 20:22:12 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_v2i	ft_set_v2i(int x, int y)
{
	t_v2i	out;

	out.x = x;
	out.y = y;
	return (out);
}

t_v2i	ft_sum_v2i(t_v2i v1, t_v2i v2)
{
	t_v2i	out;

	out.x = v1.x + v2.x;
	out.y = v1.y + v2.y;
	return (out);
}

t_v2i	ft_subtr_v2i(t_v2i v1, t_v2i v2)
{
	t_v2i	out;

	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
	return (out);
}

double	ft_length_v2i(t_v2i	vec)
{
	return (ft_sqrt((vec.x * vec.x) + (vec.y * vec.y)));
}

double	ft_distance_v2i(t_v2i v1, t_v2i v2)
{
	t_v2i	d;

	d.x = v2.x - v1.x;
	d.y = v2.x - v1.y;
	return (ft_sqrt((d.x * d.x) + (d.y * d.y)));
}
