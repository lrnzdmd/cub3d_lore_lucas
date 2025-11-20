/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:39:08 by lde-medi          #+#    #+#             */
/*   Updated: 2024/12/04 23:00:26 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;
	size_t	total_size;

	total_size = n * size;
	p = malloc(total_size);
	if (!p)
		return (NULL);
	else
		ft_memset(p, 0, total_size);
	return (p);
}
