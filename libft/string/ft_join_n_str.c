/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_n_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 02:36:07 by lde-medi          #+#    #+#             */
/*   Updated: 2025/10/15 04:38:21 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Joins n strings, into a heap allocated new string.
 * * @param s1 The first string.
 * @param s2 all the others, last string has to be NULL. 
 */
char	*ft_join_n_str(char *s1, ...)
{
	va_list	args;
	t_jns_d	dt;

	va_start(args, s1);
	va_end(args);
	dt.out = ft_strdup(s1);
	dt.out_l = ft_strlen(dt.out);
	if (!dt.out)
		return (NULL);
	va_start(args, s1);
	dt.cur_s = va_arg(args, char *);
	while (dt.cur_s)
	{
		dt.cr_len = ft_strlen(dt.cur_s);
		dt.tmp = ft_realloc(dt.out, dt.out_l + 1, dt.cr_len + dt.out_l + 1);
		if (!dt.tmp)
			return (free(dt.out), NULL);
		dt.out = dt.tmp;
		ft_strlcat(dt.out, dt.cur_s, dt.cr_len + dt.out_l + 1);
		dt.out_l += dt.cr_len;
		dt.cur_s = va_arg(args, char *);
	}
	va_end(args);
	return (dt.out);
}
