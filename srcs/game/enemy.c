/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 05:08:50 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/26 06:43:07 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update_enemy_dir(t_ent *enemy)
{
	double	rot;

	rot = ((double)rand() / RAND_MAX) * 2 * M_PI;
	enemy->data.dir.x = cos(rot);
	enemy->data.dir.y = sin(rot);
}

static void	enemy_movement_x(t_cub *data, t_ent *enemy, t_v2d step, t_v2d coll)
{
	t_v2i	map;

	coll.x = enemy->pos.x + step.x;
	if (step.x > 0)
		map.x = coll.x + ENM_HBOX_RADIUS;
	else
		map.x = coll.x - ENM_HBOX_RADIUS;
	map.y = enemy->pos.y;
	if (coll.x > data->gman.map.size.x || coll.x < 0)
		return ;
	if (data->gman.map.map[map.y][map.x] != '1'
		&& data->gman.map.map[map.y][map.x] != '2')
		enemy->pos.x = coll.x;
	else
		update_enemy_dir(enemy);
}

static void	enemy_movement_y(t_cub *data, t_ent *enemy, t_v2d step, t_v2d coll)
{
	t_v2i	map;

	coll.y = enemy->pos.y + step.y;
	if (step.y > 0)
		map.y = coll.y + ENM_HBOX_RADIUS;
	else
		map.y = coll.y - ENM_HBOX_RADIUS;
	map.x = enemy->pos.x;
	if (coll.y > data->gman.map.size.y || coll.y < 0)
		return ;
	if (data->gman.map.map[map.y][map.x] != '1'
		&& data->gman.map.map[map.y][map.x] != '2')
		enemy->pos.y = coll.y;
	else
		update_enemy_dir(enemy);
}

void	enemy_move(t_cub *data, t_ent *enemy)
{
	t_v2d	step;
	t_v2d	coll;
	double	speed;

	speed = ENM_MOV_SPD * data->d_time;
	step = ft_multiply_v2d(enemy->data.dir, speed);
	enemy_movement_x(data, enemy, step, coll);
	enemy_movement_y(data, enemy, step, coll);
}
