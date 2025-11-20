/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 03:45:20 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/20 05:17:13 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

typedef struct s_cub3d_data	t_cub;

void	init_gfx_data(t_cub	*data);
void	init_map(t_cub	*data);
void	init_player(t_cub	*data);
void	init_enemies(t_cub *data);
void	init_minimap_buffer(t_cub *data);

#endif