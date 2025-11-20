/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:49:59 by lde-medi          #+#    #+#             */
/*   Updated: 2025/01/14 00:59:00 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char	*src)
{
	size_t	i;
	size_t	n;
	char	*duplicate;	

	i = 0;
	n = ft_strlen(src) + 1;
	duplicate = (char *)ft_calloc(n, sizeof(char));
	if (!duplicate)
		return (NULL);
	while (i < n)
	{
		duplicate[i] = src[i];
		i++;
	}
	return (duplicate);
}
