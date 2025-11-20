/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:03:39 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/12 22:02:35 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_v2d	ft_rotate_v2d(t_v2d	vec, double angle)
{
	static double	sn;
	static double	cs;

	sn = sin(angle);
	cs = cos(angle);
	vec.y = vec.x * sn + vec.y * cs;
	vec.x = vec.x * cs - vec.y * sn;
	return (vec);
}
