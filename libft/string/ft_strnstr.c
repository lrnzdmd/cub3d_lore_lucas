/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:50:55 by lde-medi          #+#    #+#             */
/*   Updated: 2025/01/16 20:11:42 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(char *big, char *little, size_t	len)
{
	size_t	i;
	size_t	lit_len;

	i = 0;
	lit_len = ft_strlen(little);
	if (!lit_len)
		return (big);
	if (!big[i] || len == 0)
		return (NULL);
	while (big[i] != '\0' && (i + lit_len) <= len)
	{
		if (ft_strncmp(&big[i], little, lit_len) == 0)
			return (&big[i]);
		i++;
	}
	return (NULL);
}
