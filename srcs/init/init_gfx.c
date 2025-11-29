/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 04:04:23 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 03:31:13 by lde-medi         ###   ########.fr       */
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

	walk = &data->gfx.txt.sprts.enemy.walk;
	walk->frm_n = 4;
	walk->speed = 0.35;
	walk->loop = true;
	walk->frame = safe_calloc(data, 4, sizeof(t_img_d));
	safe_mlx_xpm_to_img(data, &walk->frame[0],
		TXT_ENM_WALK_0, &walk->frame[0].size);
	safe_mlx_xpm_to_img(data, &walk->frame[1],
		TXT_ENM_WALK_1, &walk->frame[1].size);
	safe_mlx_xpm_to_img(data, &walk->frame[2],
		TXT_ENM_WALK_2, &walk->frame[2].size);
	safe_mlx_xpm_to_img(data, &walk->frame[3],
		TXT_ENM_WALK_3, &walk->frame[3].size);
}

void	init_reload_anim(t_cub *data)
{
	t_anim	*reload;

	reload = &data->gfx.txt.sprts.plyr.reload;
	reload->frm_n = 11;
	reload->speed = 0.08;
	reload->loop = false;
	reload->frame = safe_calloc(data, 11, sizeof(t_img_d));
	safe_mlx_xpm_to_img(data, &reload->frame[0],
		TXT_RLD_0, &reload->frame[0].size);
	safe_mlx_xpm_to_img(data, &reload->frame[1],
		TXT_RLD_1, &reload->frame[1].size);
	safe_mlx_xpm_to_img(data, &reload->frame[2],
		TXT_RLD_2, &reload->frame[2].size);
	safe_mlx_xpm_to_img(data, &reload->frame[3],
		TXT_RLD_3, &reload->frame[3].size);
	safe_mlx_xpm_to_img(data, &reload->frame[4],
		TXT_RLD_4, &reload->frame[4].size);
	safe_mlx_xpm_to_img(data, &reload->frame[5],
		TXT_RLD_5, &reload->frame[5].size);
	safe_mlx_xpm_to_img(data, &reload->frame[6],
		TXT_RLD_6, &reload->frame[6].size);
	safe_mlx_xpm_to_img(data, &reload->frame[7],
		TXT_RLD_7, &reload->frame[7].size);
	safe_mlx_xpm_to_img(data, &reload->frame[8],
		TXT_RLD_8, &reload->frame[8].size);
	safe_mlx_xpm_to_img(data, &reload->frame[9],
		TXT_RLD_9, &reload->frame[9].size);
	safe_mlx_xpm_to_img(data, &reload->frame[10],
		TXT_RLD_10, &reload->frame[10].size);	
}

void	init_shoot_anim(t_cub *data)
{
	t_anim	*shoot;

	shoot = &data->gfx.txt.sprts.plyr.shoot;
	shoot->frm_n = 7;
	shoot->speed = 0.04;
	shoot->loop = false;
	shoot->frame = safe_calloc(data, 7, sizeof(t_img_d));
	safe_mlx_xpm_to_img(data, &shoot->frame[0],
		TXT_SHOOT_0, &shoot->frame[0].size);
	safe_mlx_xpm_to_img(data, &shoot->frame[1],
		TXT_SHOOT_1, &shoot->frame[1].size);
	safe_mlx_xpm_to_img(data, &shoot->frame[2],
		TXT_SHOOT_2, &shoot->frame[2].size);
	safe_mlx_xpm_to_img(data, &shoot->frame[3],
		TXT_SHOOT_3, &shoot->frame[3].size);
	safe_mlx_xpm_to_img(data, &shoot->frame[4],
		TXT_SHOOT_4, &shoot->frame[4].size);
	safe_mlx_xpm_to_img(data, &shoot->frame[5],
		TXT_SHOOT_1, &shoot->frame[5].size);
	safe_mlx_xpm_to_img(data, &shoot->frame[6],
		TXT_SHOOT_0, &shoot->frame[6].size);
}

void	init_idle_anim(t_cub *data)
{
	t_anim	*idle;

	idle = &data->gfx.txt.sprts.plyr.idle;
	idle->frm_n = 1;
	idle->speed = 0;
	idle->loop = false;
	idle->frame = safe_calloc(data, 1, sizeof(t_img_d));
	safe_mlx_xpm_to_img(data, &idle->frame[0],
		TXT_SHOOT_0, &idle->frame[0].size);
}

void	init_enemy_attack_anim(t_cub *data)
{
	t_anim	*attack;

	attack = &data->gfx.txt.sprts.enemy.attack;
	attack->frm_n = 6;
	attack->speed = ENM_ATK_SPD / 6;
	attack->loop = true;
	attack->frame = safe_calloc(data, 6, sizeof(t_img_d));
	safe_mlx_xpm_to_img(data, &attack->frame[0],
		TXT_ENM_ATK_0, &attack->frame[0].size);
	safe_mlx_xpm_to_img(data, &attack->frame[1],
		TXT_ENM_ATK_1, &attack->frame[1].size);
	safe_mlx_xpm_to_img(data, &attack->frame[2],
		TXT_ENM_ATK_2, &attack->frame[2].size);
	safe_mlx_xpm_to_img(data, &attack->frame[3],
		TXT_ENM_ATK_3, &attack->frame[3].size);
	safe_mlx_xpm_to_img(data, &attack->frame[4],
		TXT_ENM_ATK_4, &attack->frame[4].size);
	safe_mlx_xpm_to_img(data, &attack->frame[5],
		TXT_ENM_ATK_5, &attack->frame[5].size);
}

void	init_enemy_idle_anim(t_cub *data)
{
	t_anim	*idle;

	idle = &data->gfx.txt.sprts.enemy.idle;
	idle->frm_n = 4;
	idle->speed = 0.8;
	idle->loop = true;
	idle->frame = safe_calloc(data, 4, sizeof(t_img_d));
	safe_mlx_xpm_to_img(data, &idle->frame[0],
		TXT_ENM_IDLE_0, &idle->frame[0].size);
	safe_mlx_xpm_to_img(data, &idle->frame[1],
		TXT_ENM_IDLE_1, &idle->frame[1].size);
	safe_mlx_xpm_to_img(data, &idle->frame[2],
		TXT_ENM_IDLE_2, &idle->frame[2].size);
	safe_mlx_xpm_to_img(data, &idle->frame[3],
		TXT_ENM_IDLE_3, &idle->frame[3].size);
}

void	init_enemy_dead_anim(t_cub *data)
{
	t_anim	*dead;

	dead = &data->gfx.txt.sprts.enemy.dead;
	dead->frm_n = 6;
	dead->speed = 0.075;
	dead->loop = false;
	dead->frame = safe_calloc(data, 6, sizeof(t_img_d));
	safe_mlx_xpm_to_img(data, &dead->frame[0],
		TXT_ENM_DEAD_0, &dead->frame[0].size);
	safe_mlx_xpm_to_img(data, &dead->frame[1],
		TXT_ENM_DEAD_1, &dead->frame[1].size);
	safe_mlx_xpm_to_img(data, &dead->frame[2],
		TXT_ENM_DEAD_2, &dead->frame[2].size);
	safe_mlx_xpm_to_img(data, &dead->frame[3],
		TXT_ENM_DEAD_3, &dead->frame[3].size);
	safe_mlx_xpm_to_img(data, &dead->frame[4],
		TXT_ENM_DEAD_4, &dead->frame[4].size);
	safe_mlx_xpm_to_img(data, &dead->frame[5],
		TXT_ENM_DEAD_5, &dead->frame[5].size);
}

void	init_enemy_textures(t_cub *data)
{
	init_shoot_anim(data);
	init_idle_anim(data);
	init_reload_anim(data);
	init_enemy_walk_anim(data);
	init_enemy_idle_anim(data);
	init_enemy_dead_anim(data);
	init_enemy_attack_anim(data);
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
