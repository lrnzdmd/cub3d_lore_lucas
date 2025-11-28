/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:29:26 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 05:25:18 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_ESCAPE 65307
# define KEY_LSHIFT 65505
# define KEY_RSHIFT 65506
# define KEY_SPACE 32
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_F 102
# define KEY_M 109

struct s_input_data
{
	t_v2i	mouse_d;
	bool	map_toggle;
	bool	shoot;
	bool	action;
	bool	fwd;
	bool	lft;
	bool	bck;
	bool	rght;
	bool	sprint;
	bool	quit;
};

//typedef struct s_cub3d_data	t_cub;
#include "types.h"

void	input_manager(t_cub	*data);
int		key_press_handler(int keycode, t_cub *data);
int		key_release_handler(int keycode, t_cub *data);

int		mouse_move_handler(int x, int y, t_cub *data);
int		mouse_key_handler(int keycode, int x, int y, t_cub *data);

void	rotate_player(t_cub *data, bool left);
void	mouse_rotate_player(t_cub *data);
void	mouse_change_pitch(t_cub *data);
void	move_fwd_bck(t_cub *data, bool fwd);

void	pew_pew(t_cub *data);
void	open_door(t_cub	*data);

#endif