/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 06:32:10 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/26 06:42:16 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

typedef struct s_cub3d_data	t_cub;
typedef struct s_entity		t_ent;

void	enemy_state_update(t_cub *data, t_ent	*enemy);
void	enemy_action(t_cub *data, t_ent	*enemy);
void	enemy_animator(t_cub *data, t_ent *enemy);
void	enemy_move(t_cub *data, t_ent *enemy);
void	update_enemy_dir(t_ent *enemy);

#endif
