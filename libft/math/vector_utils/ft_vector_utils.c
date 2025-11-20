/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:55:29 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/12 20:10:47 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_v2d	ft_v2i_to_v2d(t_v2i v_int)
{
	t_v2d	result;

	result.x = (double)v_int.x;
	result.y = (double)v_int.y;
	return (result);
}

t_v2i	ft_v2d_to_v2i(t_v2d v_double)
{
	t_v2i	result;

	result.x = (int)(v_double.x);
	result.y = (int)(v_double.y);
	return (result);
}
