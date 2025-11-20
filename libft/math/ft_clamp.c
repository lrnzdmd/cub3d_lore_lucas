/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:06:17 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/12 22:07:09 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_clamp_i(int num, int min, int max)
{
	if (num < min)
		num = min;
	if (num > max)
		num = max;
	return (num);
}

float	ft_clamp_f(float num, float min, float max)
{
	if (num < min)
		num = min;
	if (num > max)
		num = max;
	return (num);
}

double	ft_clamp_d(double num, double min, double max)
{
	if (num < min)
		num = min;
	if (num > max)
		num = max;
	return (num);
}
