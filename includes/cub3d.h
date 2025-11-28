/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 05:31:18 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 08:19:52 by lde-medi         ###   ########.fr       */
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
# include <enemy.h>
# include <settings.h>
# include <cleanup.h>
# include <gfx.h>
# include <parsing.h>
# include <input.h>
# include <init.h>
# include <safe_ops.h>
# include <utils.h>
# include <mlx.h>
#include "types.h"

// typedef struct s_vector2int		t_v2i;
// typedef struct s_vector2double	t_v2d;
// typedef struct s_map_data		t_map;
// typedef struct s_temp_pointers	t_tmp;


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

struct s_enemy_data
{
	t_enm_st	state;
	double		anim_timer;
	int			anim_frm;
	double		st_timer;
	t_v2d		dir;
};

struct s_entity
{
	t_v2d	pos;
	double	pl_dist;
	t_img_d	*sprt;
	t_anim	*anim;
	t_ent_t	type;
	t_enm	data;
};

typedef enum e_player_states
{
	NORM,
	SHOOT
}	t_pl_st;

struct s_player_data
{
	t_pl_st	state;
	int		hp;
	t_v2d	pos;
	t_v2d	dir;
	t_v2d	plane;
	double	rot;
	int		pitch;
	double	anim_timer;
	t_ent	*target;
	double	tgt_dist;
	t_img_d	*sprt;
};

struct s_game_data
{
	t_plyr	plyr;
	t_map	map;
	t_ent	*enemies;
	int		enemies_n;
};

struct s_screen_shake
{
	bool	active;
	double	intensity;
	double	duration;
	double	time;
	double	offset;
	double	last_offset;
};

struct s_cub3d_data
{
	double			lst_frm_time;
	double			d_time;
	void			*mlx;
	void			*mlx_w;
	t_gfx			gfx;
	t_game			gman;
	t_tmp			tmp;
	t_input			input;
	t_screen_shake	shake;
};

void	update_screen_shake(t_cub *data);
void	trigger_screen_shake(t_cub *data, double intensity, double duration);
int		game_loop(t_cub *data);
void	init_screen_shake(t_cub *data);
void	door_check(t_cub	*data);

#endif