/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 06:32:10 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 01:02:28 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

#include "types.h"

void	update_enemies(t_cub *data);
void	enemy_state_update(t_cub *data, t_ent *enemy);
void	enemy_update(t_cub *data, t_ent	*enemy);
void	enemy_animator(t_cub *data, t_ent *enemy);
void	set_animation(t_ent *enemy, t_anim *anim);
void	enemy_move(t_cub *data, t_ent *enemy);
void	update_enemy_dir(t_ent *enemy);

#endif
