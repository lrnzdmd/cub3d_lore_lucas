/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 05:17:15 by luferna3          #+#    #+#             */
/*   Updated: 2025/11/28 06:41:33 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include "../libft/includes/libft.h"

typedef struct s_cub3d_data     t_cub;
typedef struct s_entity        t_ent;
typedef struct s_enemy_data    t_enm;
typedef struct s_player_data   t_plyr;
typedef struct s_map_data      t_map;
typedef struct s_temp_pointers t_tmp;
typedef struct s_input_data    t_input;
typedef struct s_graphics_data t_gfx;
typedef struct s_image_data    t_img_d;
typedef struct s_ray_data      t_ray;
typedef struct s_sprite_ray_data t_ray_s;
typedef union  u_color         t_clr;
typedef struct s_color_argb    t_argb;
typedef struct s_door_data     t_door;
typedef struct s_wall_textures t_wall_txt;
typedef struct s_enemy_textures t_enm_txt;
typedef struct s_sprites_textures t_sprt_txt;
typedef struct s_textures      t_txt;
typedef struct s_screen_shake t_screen_shake;
typedef struct s_game_data		t_game;
typedef void	(*t_state_func)(t_cub *data, t_ent *enemy);

#endif

