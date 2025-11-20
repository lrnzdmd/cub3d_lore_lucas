/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 04:40:52 by lde-medi          #+#    #+#             */
/*   Updated: 2025/09/14 08:33:12 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strchcount(const char *str, const char c)
{
	int	occur;

	occur = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == c)
			occur++;
		str++;
	}
	return (occur);
}
