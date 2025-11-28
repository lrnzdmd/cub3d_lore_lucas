/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 04:04:23 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 07:15:33 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_window_size(t_cub *data)
{
	t_v2i	screen;
	void	*mlx;
	t_img_d	*frame;

	mlx = data->mlx;
	frame = &data->gfx.fr_bf;
	mlx_get_screen_size(mlx, &screen.x, &screen.y);
	if (screen.x < SCR_SZ_X)
		frame->size.x = screen.x - 10;
	else
		frame->size.x = SCR_SZ_X;
	if (screen.y < SCR_SZ_Y)
		frame->size.y = screen.y - 10;
	else
		frame->size.y = SCR_SZ_Y;
	data->gfx.zbuffer = safe_calloc(data, frame->size.x, sizeof(double));
}

void	init_enemy_walk_anim(t_cub *data)
{
	t_anim	*walk;

	walk = &data->gfx.txt.sprts.enemy.walk_a;
	walk->frm_n = 2;
	walk->frame = safe_calloc(data, 2, sizeof(t_img_d));
	safe_mlx_xpm_to_img(data, &walk->frame[0],
		TXT_ENM_WALK_0, &walk->frame[0].size);
	safe_mlx_xpm_to_img(data, &walk->frame[1],
		TXT_ENM_WALK_1, &walk->frame[1].size);
}

void	init_enemy_textures(t_cub *data)
{
	t_enm_txt	*text;

	text = &data->gfx.txt.sprts.enemy;
	safe_mlx_xpm_to_img(data, &text->idle,
		TXT_ENM_IDLE, &text->idle.size);
	safe_mlx_xpm_to_img(data, &text->dead,
		TXT_ENM_DEAD, &text->dead.size);
	safe_mlx_xpm_to_img(data, &text->attack[0],
		TXT_ENM_ATK_0, &text->attack[0].size);
	safe_mlx_xpm_to_img(data, &text->attack[1],
		TXT_ENM_ATK_1, &text->attack[1].size);
	safe_mlx_xpm_to_img(data, &text->walk[0],
		TXT_ENM_WALK_0, &text->walk[0].size);
	safe_mlx_xpm_to_img(data, &text->walk[1],
		TXT_ENM_WALK_1, &text->walk[1].size);
	init_enemy_walk_anim(data);
}

void	init_gun_textures(t_cub *data)
{
	t_sprt_txt	*txt;

	txt = &data->gfx.txt.sprts;
	safe_mlx_xpm_to_img(data, &txt->gun[0], TXT_GUN_0, &txt->gun[0].size);
	safe_mlx_xpm_to_img(data, &txt->gun[1], TXT_GUN_1, &txt->gun[1].size);
}

void	init_gfx_data(t_cub	*data)
{
	t_img_d	*frame;
	t_img_d	*door_txt;

	frame = &data->gfx.fr_bf;
	door_txt = &data->gfx.txt.wall.dr;
	data->lst_frm_time = get_time_in_sec();
	data->d_time = 0;
	set_window_size(data);
	data->mlx_w = safe_mlx_new_window(data,
			frame->size.x, frame->size.y, "cub3d");
	safe_mlx_new_img(data, frame, frame->size.x, frame->size.y);
	safe_mlx_xpm_to_img(data, door_txt, TXT_DOOR, &door_txt->size);
	init_enemy_textures(data);
	init_gun_textures(data);
	init_minimap(data);
}
