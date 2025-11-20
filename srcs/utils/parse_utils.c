/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:51:31 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/17 04:26:03 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	find_longest_line(t_list	*list)
{
	int	len;
	int	longest;

	longest = 0;
	while (list)
	{
		len = ft_strlen(list->content);
		if (len > longest)
			longest = len;
		list = list->next;
	}
	return (longest);
}

bool	is_valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == ' ' || c == 'Z'
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '2');
}

bool	is_direction_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}
