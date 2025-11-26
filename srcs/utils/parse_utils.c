/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:51:31 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/26 06:28:38 by lde-medi         ###   ########.fr       */
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

int	find_config_id(char *line, const char *ids[6])
{
	int	i;

	i = -1;
	while (++i < 6)
		if (ft_strncmp(line, (char *)ids[i], ft_strlen(ids[i])) == 0)
			return (i);
	return (-1);
}

bool	cub_map_start(char	*line)
{
	return (*line != 'N' && *line != 'S' && *line != 'W'
		&& *line != 'E' && *line != 'F' && *line != 'C' );
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
