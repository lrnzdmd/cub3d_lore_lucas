/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:14:50 by lde-medi          #+#    #+#             */
/*   Updated: 2024/12/04 02:53:53 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*sr;

	if (!dest && !src)
		return (NULL);
	dst = dest;
	sr = src;
	i = 0;
	while (i < n)
	{
		dst[i] = sr[i];
		i++;
	}
	return (dst);
}
