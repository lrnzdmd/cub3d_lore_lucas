/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:36:57 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 02:43:26 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# define TARGET_FR_TIME 0.0166666666666667
# define SCR_SZ_X 900
# define SCR_SZ_Y 600
# define FOV_PLANE 0.66f
# define MAP_CLR_WL 0xFF644117
# define MAP_CLR_DR 0xFF009C8C
# define MAP_CLR_BG 0xFF002147

# define TXT_ENEMY "./assets/textures/bear.xpm"
# define TXT_DOOR "./assets/textures/door.xpm"
# define TXT_GUN_0 "./assets/textures/gun0.xpm"
# define TXT_GUN_1 "./assets/textures/gun1.xpm"
# define TXT_SHOOT_0 "./assets/textures/shoot0.xpm"
# define TXT_SHOOT_1 "./assets/textures/shoot1.xpm"
# define TXT_SHOOT_2 "./assets/textures/shoot2.xpm"
# define TXT_SHOOT_3 "./assets/textures/shoot3.xpm"
# define TXT_SHOOT_4 "./assets/textures/shoot4.xpm"
# define TXT_ENM_ATK_0 "./assets/textures/atk0.xpm"
# define TXT_ENM_ATK_1 "./assets/textures/atk1.xpm"
# define TXT_ENM_ATK_2 "./assets/textures/atk2.xpm"
# define TXT_ENM_ATK_3 "./assets/textures/atk3.xpm"
# define TXT_ENM_ATK_4 "./assets/textures/atk4.xpm"
# define TXT_ENM_ATK_5 "./assets/textures/atk0.xpm"
# define TXT_ENM_WALK_0 "./assets/textures/walk0.xpm"
# define TXT_ENM_WALK_1 "./assets/textures/walk1.xpm"
# define TXT_ENM_WALK_2 "./assets/textures/walk2.xpm"
# define TXT_ENM_WALK_3 "./assets/textures/walk3.xpm"
# define TXT_ENM_IDLE_0 "./assets/textures/idle0.xpm"
# define TXT_ENM_IDLE_1 "./assets/textures/idle1.xpm"
# define TXT_ENM_IDLE_2 "./assets/textures/idle2.xpm"
# define TXT_ENM_IDLE_3 "./assets/textures/idle3.xpm"
# define TXT_ENM_DEAD_0 "./assets/textures/dead0.xpm"
# define TXT_ENM_DEAD_1 "./assets/textures/dead1.xpm"
# define TXT_ENM_DEAD_2 "./assets/textures/dead2.xpm"
# define TXT_ENM_DEAD_3 "./assets/textures/dead3.xpm"
# define TXT_ENM_DEAD_4 "./assets/textures/dead4.xpm"
# define TXT_ENM_DEAD_5 "./assets/textures/dead5.xpm"
# define ANM_SPD_SHOOT 0.8
# define ANM_SPD_ENM_ATK 0.5
# define ANM_SPD_ENM_WALK 0.8

#include "types.h"

typedef enum e_door_orientation
{
	H,
	V
}	t_d_hor;

struct s_door_data
{
	t_v2i	pos;
	bool	open;
	t_d_hor	hor;
};

struct s_map_data
{
	char	**map;
	int		tile_size;
	t_v2i	size;
	int		doors_n;
	bool	doors_open;
	t_door	*doors;
	t_door	***door_map;
};

struct s_color_argb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
};

union u_color
{
	int		color;
	t_argb	c;
};

struct s_sprite_ray_data
{
	int		color;
	double	inv_det;
	double	scr_x;
	double	size;
	t_v2i	draw_st;
	t_v2i	draw_end;
	t_v2d	rel_pos;
	t_v2d	transf;

};

struct s_ray_data
{
	int		color;
	double	ln_hght;
	double	p_dist;
	double	draw_st;
	double	draw_end;
	double	dr_dist;
	double	wl_dist;
	double	cam_x;
	t_v2d	dir;
	t_v2d	st_pos;
	t_v2d	end_pos;
	t_v2d	sd_dist;
	t_v2d	d_dist;
	t_v2i	map;
	t_v2i	step;
	bool	hit;
	bool	door_hit;
	bool	side;
};

struct s_image_data
{
	void		*img_p;
	char		*addr;
	t_v2i		size;
	int			sz_line;
	int			bpp;
	int			end;
};

struct s_wall_textures
{
	t_img_d	n;
	t_img_d	s;
	t_img_d	w;
	t_img_d	e;
	t_img_d	dr;
};

struct s_animation
{
	t_img_d	*frame;
	int		frm_n;
	double	speed;
	bool	loop;
};

struct s_enemy_textures
{
	t_anim	walk;
	t_anim	attack;
	t_anim	dead;
	t_anim	idle;
};

struct s_player_textures
{
	t_anim	idle;
	t_anim	shoot;
	t_anim	reload;
};

struct s_sprites_textures
{
	t_enm_txt	enemy;
	t_plyr_txt	plyr;
	t_img_d		gun[2];
};

struct s_textures
{
	t_wall_txt	wall;
	t_sprt_txt	sprts;
};

struct s_graphics_data
{
	t_clr		ceil_c;
	t_clr		grnd_c;
	t_txt		txt;
	t_img_d		fr_bf;
	t_img_d		m_map;
	double		*zbuffer;
};

inline static char	*calc_dest_addr(t_img_d	*img, t_v2i	pos)
{
	char	*addr;

	if (pos.x < 0)
		pos.x = 0;
	if (pos.x > img->size.x)
		pos.x = img->size.x;
	if (pos.y < 0)
		pos.y = 0;
	if (pos.y > img->size.y)
		pos.y = img->size.y;
	addr = img->addr;
	addr += (pos.y * img->sz_line) + (pos.x * (img->bpp / 8));
	return (addr);
}

static inline t_v2i	map_to_pixel_coords(t_map map, t_v2d	map_cd)
{
	map_cd.x *= map.tile_size;
	map_cd.y *= map.tile_size;
	return ((t_v2i){map_cd.x, map_cd.y});
}

void	init_minimap(t_cub *data);
void	draw_minimap(t_cub *data);
void	draw_player_minimap(t_cub *data);
void	render_enemies(t_cub *data);
int		get_sprite_pixel(t_img_d *txt, t_v2i pos);
void	render_world(t_cub *data);
void	player_animator(t_cub *data);
void	set_pl_animation(t_plyr *plyr, t_anim *anim);
void	render_player(t_cub *data);
void	draw_game(t_cub *data);
void	draw_background(t_cub	*data);

void	drawline_to_img(t_img_d *img, t_v2i start, t_v2i end, int color);
void	drawrect_to_img(t_img_d	*img, t_v2i top_l, t_v2i bot_r, int color);
void	drawrectrd_to_img(t_img_d	*img, t_v2i top_l, t_v2i bot_r, int color);
void	drawcircle_to_img(t_img_d *img, t_v2i center, int r, int color);
void	draw_h_line(t_img_d *img, t_v2i start, t_v2i end, int color);
void	draw_v_line(t_img_d *img, t_v2i start, t_v2i end, int color);

void	init_sprite_ray(t_cub *data, t_ent *enemy, t_ray_s *ray);
int		get_sprite_pixel(t_img_d *txt, t_v2i pos);
bool	is_shootable(t_cub *data, t_ray_s ray);
void	render_sprite(t_cub *data, t_ent *enemy, t_ray_s ray);
void	render_crosshair(t_cub *data);
void	hud_health_ammo(t_cub *data);

void	init_ray_dir(t_cub *data, t_ray *ray, int x);
void	init_ray_d_dist(t_ray *ray);
void	init_ray_sd_dist(t_ray *ray);
void	ray_dda(t_ray *ray);
void	init_ray(t_cub *data, t_ray *ray, int x);
void	order_sprites(t_cub *data);
bool	door_dda(t_ray *ray, t_door ***doors);

#endif