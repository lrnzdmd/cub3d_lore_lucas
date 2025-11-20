/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 03:48:55 by lde-medi          #+#    #+#             */
/*   Updated: 2025/10/25 17:31:56 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	int					i;
	unsigned char		uc;

	i = 0;
	if (!s)
		return (NULL);
	uc = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == uc)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == uc)
		return ((char *)s + i);
	return (NULL);
}
