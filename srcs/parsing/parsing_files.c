/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:43:00 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/17 07:30:06 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static bool	parse_fc_color(t_cub *data, char *line, int flr_ceil);
static bool	parse_wall_text(t_cub	*data, char *line, int dir);
static bool	validate_color_line(char **line);
static bool	ft_isdigit_str(char *str);

void	parse_text_color(t_cub *data, char *line)
{
	int			i;
	const char	*ids[6] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	static bool	found[6] = {false};

	i = -1;
	while (++i < 6)
	{
		if (ft_strncmp(line, (char *)ids[i], ft_strlen(ids[i])) == 0)
		{
			if (found[i])
				exit_with_error(data, ERR_DUPL_COL_TXT, 1);
			line += ft_strlen(ids[i]);
			if (i <= EA)
			{
				if (!parse_wall_text(data, line, i))
					exit_with_error(data, ERR_TXT_FILE, 1);
			}
			else
				if (!parse_fc_color(data, line, i))
					exit_with_error(data, ERR_CLR_FMT, 1);
			found[i] = true;
		}
	}
}

static bool	parse_fc_color(t_cub	*data, char	*line, int flr_ceil)
{
	t_clr	*ptr;

	data->tmp.str_2 = ft_strtrim(line, " \t\n\v\f\r");
	data->tmp.arr = ft_split(data->tmp.str_2, ',');
	ft_multifree(1, &data->tmp.str_2);
	if (!validate_color_line(data->tmp.arr))
		return (free_array(&data->tmp.arr), false);
	ptr = ft_ternop(flr_ceil == FLOOR, &data->gfx.grnd_c, &data->gfx.ceil_c);
	*ptr = set_color(ft_atoi(data->tmp.arr[0]),
			ft_atoi(data->tmp.arr[1]), ft_atoi(data->tmp.arr[2]), 255);
	free_array(&data->tmp.arr);
	return (true);
}

static bool	parse_wall_text(t_cub	*data, char	*line, int dir)
{
	t_img_d	*img;

	data->tmp.str_2 = ft_strtrim(line, " \t\n\v\f\r");
	if (!check_file_extension(data->tmp.str_2, ".xpm"))
		return (ft_multifree(1, &data->tmp.str_2), false);
	if (dir == NO)
		img = &data->gfx.txt.wall.n;
	else if (dir == SO)
		img = &data->gfx.txt.wall.s;
	else if (dir == WE)
		img = &data->gfx.txt.wall.w;
	else
		img = &data->gfx.txt.wall.e;
	img->img_p = mlx_xpm_file_to_image(data->mlx, data->tmp.str_2,
			&img->size.x, &img->size.y);
	if (!img->img_p || img->size.x != img->size.y)
		return (ft_multifree(1, &data->tmp.str_2), false);
	img->addr = mlx_get_data_addr(img->img_p, &img->bpp,
			&img->sz_line, &img->end);
	ft_multifree(1, &data->tmp.str_2);
	return (true);
}

static bool	validate_color_line(char **line)
{
	int	i;

	if (ft_arr_len(line) != 3)
		return (false);
	i = -1;
	while (++i < 3)
	{
		if (ft_strlen(line[i]) > 3
			|| !ft_isdigit_str(line[i]) || ft_atoi(line[i]) > 255)
			return (false);
	}
	return (true);
}

static bool	ft_isdigit_str(char	*str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
