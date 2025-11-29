/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:54:17 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 04:40:52 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include <types.h>

int		exit_game(t_cub	*data);
void	exit_with_error(t_cub	*data, char	*msg, int exit_code);
void	exit_with_strerror(t_cub	*data, char	*msg, int exit_code);
void	free_tmp_pointers(t_cub	*data);
void	free_gfx_data(t_cub	*data);
void	free_array(char	***arr);
void	free_list(t_list	**lst);

#endif