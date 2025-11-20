/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:51:30 by lde-medi          #+#    #+#             */
/*   Updated: 2025/01/17 20:06:36 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(const char	*s1, const char	*s2)
{
	int		s1_len;
	int		s2_len;
	char	*joined_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, (char *)s1, s1_len + 1);
	ft_strlcat(joined_str, (char *)s2, s1_len + s2_len + 1);
	return (joined_str);
}
