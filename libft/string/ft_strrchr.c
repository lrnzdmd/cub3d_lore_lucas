/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 05:08:19 by lde-medi          #+#    #+#             */
/*   Updated: 2024/12/02 22:55:50 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int					i;
	unsigned char		uc;
	int					s_len;

	uc = (unsigned char)c;
	s_len = ft_strlen(s);
	i = s_len;
	while (i >= 0)
	{
		if (s[i] == uc)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (NULL);
}
