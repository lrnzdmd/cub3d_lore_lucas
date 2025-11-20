/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 03:49:23 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/17 05:06:16 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	free_all_data(t_cub	*data);

int	exit_game(t_cub	*data)
{
	free_all_data(data);
	exit(0);
}

void	exit_with_error(t_cub	*data, char	*msg, int exit_code)
{
	ft_dprintf(STDERR_FILENO, "Error\ncub3d: %s\n", msg);
	free_all_data(data);
	exit(exit_code);
}

void	exit_with_strerror(t_cub	*data, char	*msg, int exit_code)
{
	ft_dprintf(STDERR_FILENO, "Error\ncub3d: %s: %s\n", msg, strerror(errno));
	free_all_data(data);
	exit(exit_code);
}

void	free_map_data(t_cub	*data)
{
	int	i;

	if (data->gman.map.map)
		free_array(&data->gman.map.map);
	if (data->gman.map.doors)
		ft_multifree(1, &data->gman.map.doors);
	if (data->gman.map.door_map)
	{
		i = -1;
		while (++i < data->gman.map.size.y)
			free(data->gman.map.door_map[i]);
		free(data->gman.map.door_map);
	}
}

static void	free_all_data(t_cub	*data)
{
	void	*mlx;
	void	*mlx_w;

	mlx = data->mlx;
	mlx_w = data->mlx_w;
	if (!data)
		return ;
	free_gfx_data(data);
	free_tmp_pointers(data);
	if (mlx_w)
		mlx_destroy_window(mlx, mlx_w);
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
	free_map_data(data);
}
