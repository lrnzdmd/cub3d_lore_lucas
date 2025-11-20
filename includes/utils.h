/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:50:16 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/20 00:46:13 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_list			t_list;
typedef struct s_ray			t_ray;
typedef struct s_image_data		t_img_d;
typedef union u_color			t_clr;

void	update_player_vectors(t_cub *data);
t_v2d	ft_rotate_v2d(t_v2d	vec, double angle);

int		find_longest_line(t_list	*list);
bool	is_valid_map_char(char c);
bool	is_direction_char(char c);

t_clr	set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
int		darken_color(int color, int amount);

double	get_time_in_sec(void);
void	calc_delta_time(t_cub *data);

#endif