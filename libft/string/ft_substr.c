/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:58:45 by lde-medi          #+#    #+#             */
/*   Updated: 2025/01/14 18:29:11 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start >= (unsigned int)ft_strlen(s))
	{
		sub = (char *)ft_calloc(1, sizeof(char));
		if (!sub)
			return (NULL);
		return (sub);
	}
	if (len + start > (unsigned int)ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (char *)&s[start], len + 1);
	return (sub);
}
