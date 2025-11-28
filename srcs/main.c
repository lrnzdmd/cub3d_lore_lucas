/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 05:30:54 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 02:11:26 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char	**av)
{
	static t_cub	data;

	data.mlx = safe_mlx_init(&data);
	parse_cub3d(&data, ac, av);
	init_gfx_data(&data);
	init_player(&data);
	init_enemies(&data);
	init_mouse_controls(&data);
	init_screen_shake(&data);
	mlx_hook(data.mlx_w, 17, 0, exit_game, &data);
	mlx_hook(data.mlx_w, 2, 1L << 0, key_press_handler, &data);
	mlx_hook(data.mlx_w, 3, 1L << 1, key_release_handler, &data);
	mlx_mouse_hook(data.mlx_w, mouse_key_handler, &data);
	mlx_hook(data.mlx_w, 6, 1L << 6, mouse_move_handler, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
}
