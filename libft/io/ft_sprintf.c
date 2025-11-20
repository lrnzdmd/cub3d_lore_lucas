/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:17:19 by lde-medi          #+#    #+#             */
/*   Updated: 2025/10/30 00:29:30 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_sprintf(const char *str, ...)
{
	t_pf_data	data;
	va_list		ap;
	int			i;

	va_start(ap, str);
	if (!init_pf_buf(&data, (char *)str))
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (!convert(&data, str[i + 1], &ap))
				return (NULL);
			i++;
		}
		else
		{
			if (!w_ch_to_b(&data, str[i]))
				return (NULL);
		}
	}
	va_end(ap);
	return (data.buf);
}
