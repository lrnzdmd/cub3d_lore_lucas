/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:50:16 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 05:05:28 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <types.h>

void	update_player_vectors(t_cub *data);
t_v2d	ft_rotate_v2d(t_v2d	vec, double angle);

int		find_longest_line(t_list	*list);
int		find_config_id(char *line, const char *ids[6]);
bool	cub_map_start(char	*line);
bool	is_valid_map_char(char c);
bool	is_direction_char(char c);

t_clr	set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
int		darken_color(int color, int amount);
void	draw_map_tile(t_cub *data, t_img_d	*img, t_v2i map);
void	draw_bullet(t_img_d *frame, t_v2i icn_pos, t_v2i icn_size);
void	draw_cross(t_img_d *frame, t_v2i icn_pos, t_v2i icn_size);

double	get_time_in_sec(void);
void	calc_delta_time(t_cub *data);

#endif