/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 05:31:18 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/23 23:08:10 by lde-medi         ###   ########.fr       */
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
# include <settings.h>
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

typedef enum e_entity_types
{
	ITEM,
	ENEMY
}	t_ent_t;

typedef enum s_enemy_state
{
	IDLE,
	PATROL,
	CHASE,
	ATTACK,
	DEAD
}	t_enm_st;

typedef struct s_enemy_data
{
	t_enm_st	state;
	bool		shootable;
	double		anim_timer;
	int			anim_frm;
	double		st_timer;
	t_v2d		dir;
}	t_enm;

typedef struct s_entity
{
	t_v2d	pos;
	double	pl_dist;
	t_img_d	*sprt;
	t_ent_t	type;
	t_enm	data;
}	t_ent;

typedef enum	e_player_states
{
	NORM,
	SHOOT
}	t_pl_st;

typedef struct s_player_data
{
	t_pl_st	state;
	int		hp;
	t_v2d	pos;
	t_v2d	dir;
	t_v2d	plane;
	double	rot;
	double	anim_timer;
	t_img_d	*sprt;
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

void	enemy_state_update(t_cub *data, t_ent	*enemy);
void	enemy_action(t_cub *data, t_ent	*enemy);
void	enemy_animator(t_cub *data, t_ent *enemy);

#endif