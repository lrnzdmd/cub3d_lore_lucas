/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v2d_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:09:50 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/12 22:16:23 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_v2d	ft_multiply_v2d(t_v2d vec, double scalar)
{
	vec.x *= scalar;
	vec.y *= scalar;
	return (vec);
}
