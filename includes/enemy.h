/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 06:32:10 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 06:39:40 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

#include "types.h"

void	update_enemies(t_cub *data);
void	enemy_state_update(t_cub *data, t_ent *enemy);
void	enemy_action(t_cub *data, t_ent	*enemy);
void	enemy_animator(t_cub *data, t_ent *enemy);
void	enemy_move(t_cub *data, t_ent *enemy);
void	update_enemy_dir(t_ent *enemy);

#endif
