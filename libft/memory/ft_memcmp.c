/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:32:48 by lde-medi          #+#    #+#             */
/*   Updated: 2025/01/16 20:50:35 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *p1, const void *p2, size_t num)
{
	size_t				i;
	const unsigned char	*cp1;
	const unsigned char	*cp2;

	i = 0;
	cp1 = p1;
	cp2 = p2;
	while (i < num)
	{
		if (cp1[i] != cp2[i])
			return (cp1[i] - cp2[i]);
		i++;
	}
	return (0);
}
