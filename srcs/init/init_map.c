/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 03:46:05 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/20 00:44:20 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static char	*copy_map_line(t_cub	*data, char	*line, int sz_x);

void	init_map(t_cub	*data)
{
	int		i;
	t_list	*tmp;

	data->gman.map.size.y = ft_lstsize(data->tmp.lst);
	data->gman.map.size.x = find_longest_line(data->tmp.lst);
	if (data->gman.map.size.x * data->gman.map.size.y < 9)
		exit_with_error(data, "map too small", 1);
	data->gman.map.map = safe_calloc(data,
			data->gman.map.size.y + 1, sizeof(char *));
	i = -1;
	tmp = data->tmp.lst;
	while (++i < data->gman.map.size.y)
	{
		data->gman.map.map[i] = copy_map_line(data,
				tmp->content, data->gman.map.size.x);
		tmp = tmp->next;
	}
	data->input.map_toggle = true;
}

static char	*copy_map_line(t_cub	*data, char	*line, int sz_x)
{
	char	*out;

	out = safe_calloc(data, sz_x + 1, sizeof(char));
	data->tmp.i = -1;
	while (line[++data->tmp.i])
		out[data->tmp.i] = line[data->tmp.i];
	if (ft_strlen(line) < sz_x)
	{
		while (data->tmp.i < sz_x)
			out[data->tmp.i++] = ' ';
	}
	return (out);
}
