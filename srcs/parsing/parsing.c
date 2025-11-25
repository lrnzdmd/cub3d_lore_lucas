/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:27:17 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/25 05:14:45 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	read_cub_file(t_cub	*data, char	*av);
static void	parse_first_section(t_cub	*data, bool *map_st);
static void	parse_file_loop(t_cub	*data, bool	*map_st);
static bool	cub_map_start(char	*line);

void	parse_cub3d(t_cub	*data, int ac, char	**av)
{
	validate_args(data, ac, av);
	read_cub_file(data, av[1]);
	parse_map(data);
}

static void	read_cub_file(t_cub	*data, char	*av)
{
	bool	map_st;

	data->tmp.fd = open(av, O_RDONLY);
	map_st = false;
	parse_file_loop(data, &map_st);
	ft_get_next_line(data->tmp.fd, GNL_FLUSH);
	close(data->tmp.fd);
	data->tmp.fd = -1;
}

static void	parse_first_section(t_cub	*data, bool *map_st)
{
	if (cub_map_start(data->tmp.str_1))
	{
		parse_text_color(data, data->tmp.str_1, true);
		*map_st = true;
	}
	else
		parse_text_color(data, data->tmp.str_1, false);
}

// static void	parse_file_loop(t_cub *data, bool *map_st)
// {
// 	const char	*config_trim = " \t\n\v\f\r";
// 	const char	*map_trim = "\n\r";

// 	while (1)
// 	{
// 		data->tmp.gnl = ft_get_next_line(data->tmp.fd, GNL_NOFLUSH);
// 		if (!data->tmp.gnl)
// 			break ;
// 		data->tmp.str_1 = safe_strtrim(data, data->tmp.gnl,
// 				(char *)config_trim);
// 		if (!*map_st && !*data->tmp.str_1)
// 		{
// 			ft_multifree(2, &data->tmp.str_1, &data->tmp.gnl);
// 			continue ;
// 		}
// 		if (!*map_st)
// 		{
// 			parse_first_section(data, map_st);
// 			if (*map_st)
// 			{
// 				ft_multifree(1, &data->tmp.str_1);
// 				data->tmp.str_1 = safe_strtrim(data, data->tmp.gnl,
// 						(char *)map_trim);
// 			}
// 		}
// 		else
// 		{
// 			ft_multifree(1, &data->tmp.str_1);
// 			data->tmp.str_1 = safe_strtrim(data, data->tmp.gnl,
// 					(char *)map_trim);
// 		}
// 		if (*map_st)
// 		{
// 			safe_append_lst(data, &data->tmp.lst, data->tmp.str_1);
// 			data->tmp.str_1 = NULL;
// 		}
// 		ft_multifree(2, &data->tmp.str_1, &data->tmp.gnl);
// 	}
// }

static void	handle_map_transition(t_cub *data, bool *map_st)
{
	if (!*map_st)
		parse_first_section(data, map_st);
	if (*map_st)
	{
		ft_multifree(1, &data->tmp.str_1);
		data->tmp.str_1 = safe_strtrim(data, data->tmp.gnl, "\n\r");
		safe_append_lst(data, &data->tmp.lst, data->tmp.str_1);
		data->tmp.str_1 = NULL;
	}
}

static void	parse_file_loop(t_cub *data, bool *map_st)
{
	const char	*config_trim = " \t\n\v\f\r";

	while (1)
	{
		data->tmp.gnl = ft_get_next_line(data->tmp.fd, GNL_NOFLUSH);
		if (!data->tmp.gnl)
			break ;
		data->tmp.str_1 = safe_strtrim(data, data->tmp.gnl,
				(char *)config_trim);
		if (!*map_st && !*data->tmp.str_1)
		{
			ft_multifree(2, &data->tmp.str_1, &data->tmp.gnl);
			continue ;
		}
		handle_map_transition(data, map_st);
		ft_multifree(2, &data->tmp.str_1, &data->tmp.gnl);
	}
}

static bool	cub_map_start(char	*line)
{
	return (*line != 'N' && *line != 'S' && *line != 'W'
		&& *line != 'E' && *line != 'F' && *line != 'C' );
}
