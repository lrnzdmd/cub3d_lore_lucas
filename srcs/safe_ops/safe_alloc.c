/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 06:54:01 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 04:05:39 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	*safe_calloc(t_cub	*data, size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
		exit_with_strerror(data, "ft_calloc", 1);
	return (ptr);
}

void	safe_append_lst(t_cub	*data, t_list	**lst, void	*content)
{
	t_list	*new;

	new = safe_calloc(data, 1, sizeof(t_list));
	new->content = content;
	ft_lstadd_back(lst, new);
}

char	*safe_strtrim(t_cub *data, const char *src, const char *set)
{
	char	*ptr;

	ptr = ft_strtrim(src, set);
	if (!ptr)
		exit_with_strerror(data, "ft_strtrim", 1);
	return (ptr);
}

char	**safe_split(t_cub	*data, const char	*s, char c)
{
	char	**ptr;

	ptr = ft_split(s, c);
	if (!ptr)
		exit_with_strerror(data, "ft_split", 1);
	return (ptr);
}
