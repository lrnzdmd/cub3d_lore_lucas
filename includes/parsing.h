/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 03:11:04 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/24 01:45:52 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define ERR_USAGE "usage: ./cub3d mapname.cub"
# define ERR_MAP_EXT "invalid map file extension"
# define ERR_CUB_ISDIR "Invalid file path (is a directory)"
# define ERR_DUPL_COL_TXT "found duplicate texture or color in file"
# define ERR_TXT_FILE "error parsing texture file (need .xpm square texture)"
# define ERR_CLR_FMT "error parsing color line (format C/F 255,255,255)"
# define ERR_MAP_INV_CH "map contains invalid characters"
# define ERR_MAP_INV_BRD "map area (0) must be surrounded by (1)"
# define ERR_MAP_INV_DR "doors (2) can only be connected to two walls (1)"

typedef enum e_parser_id
{
	NO,
	SO,
	WE,
	EA,
	FLOOR,
	CEILING
}	t_en_cl;

typedef struct s_temp_pointers
{
	int		i;
	int		fd;
	char	**arr;
	char	*str_1;
	char	*str_2;
	char	*gnl;
	t_list	*lst;
	t_d_hor	lst_dr_h;
}	t_tmp;

typedef struct s_cub3d_data	t_cub;

void	parse_cub3d(t_cub	*data, int ac, char **av);
void	validate_args(t_cub	*data, int ac, char	**av);
bool	validate_map_doors(t_cub *data);
void	parse_map(t_cub	*data);
void	parse_text_color(t_cub	*data, char	*line);
bool	check_file_extension(char	*filename, char *extension);

#endif