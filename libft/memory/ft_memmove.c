/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:45:08 by lde-medi          #+#    #+#             */
/*   Updated: 2025/01/17 19:56:03 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*sr;

	if (!dest && !src)
		return (NULL);
	dst = dest;
	sr = src;
	if (dst > sr)
		while (n--)
			dst[n] = sr[n];
	else
		ft_memcpy(dest, src, n);
	return (dst);
}
