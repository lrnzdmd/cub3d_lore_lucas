/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:30:28 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 04:47:33 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	input_manager(t_cub	*data)
{
	t_input	input;

	input = data->input;
	if (input.mouse_d.x != 0)
		mouse_rotate_player(data);
	if (input.mouse_d.y != 0)
		mouse_change_pitch(data);
	if (input.rght)
		rotate_player(data, false);
	if (input.lft)
		rotate_player(data, true);
	if (input.fwd)
		move_fwd_bck(data, true);
	if (input.bck)
		move_fwd_bck(data, false);
	if (input.action)
		open_door(data);
	if (input.quit)
		exit_game(data);
}

int	key_press_handler(int keycode, t_cub *data)
{
	t_input	*input;

	input = &data->input;
	if ((keycode == KEY_W || keycode == KEY_UP))
		input->fwd = true;
	if ((keycode == KEY_A || keycode == KEY_LEFT))
		input->lft = true;
	if ((keycode == KEY_S || keycode == KEY_DOWN))
		input->bck = true;
	if ((keycode == KEY_D || keycode == KEY_RIGHT))
		input->rght = true;
	if (keycode == KEY_F)
		input->action = true;
	if (keycode == KEY_R)
		input->reload = true;
	if (keycode == KEY_SPACE)
		input->shoot = true;
	if (keycode == KEY_LSHIFT || keycode == KEY_RSHIFT)
		input->sprint = true;
	if (keycode == KEY_ESCAPE)
		input->quit = true;
	if (keycode == KEY_M)
		input->map_toggle = !input->map_toggle;
	return (0);
}

int	key_release_handler(int keycode, t_cub *data)
{
	t_input	*input;

	input = &data->input;
	if ((keycode == KEY_W || keycode == KEY_UP))
		input->fwd = false;
	if ((keycode == KEY_A || keycode == KEY_LEFT))
		input->lft = false;
	if ((keycode == KEY_S || keycode == KEY_DOWN))
		input->bck = false;
	if ((keycode == KEY_D || keycode == KEY_RIGHT))
		input->rght = false;
	if (keycode == KEY_F)
		input->action = false;
	if (keycode == KEY_R)
		input->reload = false;
	if (keycode == KEY_SPACE)
		input->shoot = false;
	if (keycode == KEY_LSHIFT || keycode == KEY_RSHIFT)
		input->sprint = false;
	if (keycode == KEY_ESCAPE)
		input->quit = false;
	return (0);
}
