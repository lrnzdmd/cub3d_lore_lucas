/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 04:04:23 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 04:49:39 by lde-medi         ###   ########.fr       */
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

void	load_anim(t_cub *data, t_anim *anim, char *path, int frm_n)
{
	int	i;

	anim->frm_n = frm_n;
	anim->frame = safe_calloc(data, frm_n, sizeof(t_img_d));
	i = -1;
	while (++i < frm_n)
	{
		data->tmp.str_1 = ft_sprintf("%s%d.xpm", path, i);
		if (!data->tmp.str_1)
			exit_with_error(data, "ft_sprintf", 1);
		safe_mlx_xpm_to_img(data, &anim->frame[i],
			data->tmp.str_1, &anim->frame[i].size);
		ft_multifree(1, &data->tmp.str_1);
	}
}

void	set_anim_data(t_anim *anim, double speed, bool loop)
{
	anim->loop = loop;
	anim->speed = speed;
}

void	init_enemy_textures(t_cub *data)
{
	t_enm_txt	*enemy;

	enemy = &data->gfx.txt.sprts.enemy;
	load_anim(data, &enemy->walk, TXT_ENM_WALK, 4);
	set_anim_data(&enemy->walk, ANM_SPD_ENM_WALK, true);
	load_anim(data, &enemy->idle, TXT_ENM_IDLE, 4);
	set_anim_data(&enemy->idle, ANM_SPD_ENM_IDLE, true);
	load_anim(data, &enemy->dead, TXT_ENM_DEAD, 6);
	set_anim_data(&enemy->dead, ANM_SPD_ENM_DEAD, false);
	load_anim(data, &enemy->attack, TXT_ENM_ATK, 6);
	set_anim_data(&enemy->attack, ENM_ATK_SPD * 0.125, false);
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
	load_anim(data, &data->gfx.txt.sprts.plyr.shoot, TXT_SHOOT, 7);
	set_anim_data(&data->gfx.txt.sprts.plyr.shoot, ANM_SPD_SHOOT, false);
	load_anim(data, &data->gfx.txt.sprts.plyr.reload, TXT_RLD, 11);
	set_anim_data(&data->gfx.txt.sprts.plyr.reload, ANM_SPD_RLD, false);
	load_anim(data, &data->gfx.txt.sprts.plyr.idle, TXT_SHOOT, 1);
	set_anim_data(&data->gfx.txt.sprts.plyr.idle, 0, false);
	init_enemy_textures(data);
	init_minimap(data);
}
