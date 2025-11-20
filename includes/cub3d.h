/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 05:31:18 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/20 05:27:45 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <string.h>
# include <math.h>
# include <sys/time.h>

# include <libft.h>
# include <cleanup.h>
# include <gfx.h>
# include <parsing.h>
# include <input.h>
# include <init.h>
# include <safe_ops.h>
# include <utils.h>
# include <mlx.h>

# define M_PI 3.14159265358979323846

typedef struct s_vector2int		t_v2i;
typedef struct s_vector2double	t_v2d;
typedef struct s_map_data		t_map;
typedef struct s_temp_pointers	t_tmp;

#	define ENM_AI_TIMER 3

typedef enum e_entity_types
{
	ITEM,
	ENEMY
}	t_ent_t;

typedef enum s_enemy_state
{
	IDLE,
	PATROL
}	t_enm_st;

typedef struct s_enemy_data
{
	t_enm_st	state;
	double		st_timer;
	t_v2d		dir;
}	t_enm;

typedef struct s_entity
{
	t_v2d	pos;
	double	pl_dist;
	t_ent_t	type;
	t_enm	data;
}	t_ent;

typedef struct s_player_data
{
	t_v2d	pos;
	t_v2d	dir;
	t_v2d	plane;
	double	rot;
}	t_plyr;

typedef struct s_game_data
{
	t_plyr	plyr;
	t_map	map;
	t_ent	*enemies;
	int		enemies_n;
}	t_game;

typedef struct s_cub3d_data
{
	double		lst_frm_time;
	double		d_time;
	void		*mlx;
	void		*mlx_w;
	t_gfx		gfx;
	t_game		gman;
	t_tmp		tmp;
	t_input		input;
}	t_cub;

void	update_enemy_states(t_cub *data, t_ent	*enemy, int	enm_n);
void	enemy_action(t_cub *data, t_ent	*enemy, int	enm_n);

#endif