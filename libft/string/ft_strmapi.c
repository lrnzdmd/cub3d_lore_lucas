/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:51:29 by lde-medi          #+#    #+#             */
/*   Updated: 2024/12/04 23:01:54 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*out;

	out = ft_strdup(s);
	if (!out)
		return (NULL);
	i = 0;
	while ((int)i < ft_strlen(out))
	{
		out[i] = f(i, out[i]);
		i++;
	}
	return (out);
}
