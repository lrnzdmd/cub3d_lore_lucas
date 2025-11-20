/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_mlx_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:08:53 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/20 00:30:33 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	*safe_mlx_init(t_cub	*data)
{
	void	*ptr;

	ptr = mlx_init();
	if (!ptr)
		exit_with_strerror(data, "mlx_init", 1);
	return (ptr);
}

void	*safe_mlx_new_window(t_cub	*data, int sz_x, int sz_y, char	*title)
{
	void	*ptr;

	ptr = mlx_new_window(data->mlx, sz_x, sz_y, title);
	if (!ptr)
		exit_with_strerror(data, "mlx_new_window", 1);
	return (ptr);
}

void	safe_mlx_free_img(void *mlx, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}

void	safe_mlx_new_img(t_cub	*data, t_img_d	*img, int sz_x, int sz_y)
{
	img->img_p = mlx_new_image(data->mlx, sz_x, sz_y);
	if (!img->img_p)
		exit_with_error(data, "mlx_new_img", 1);
	img->addr = mlx_get_data_addr(img->img_p,
			&img->bpp, &img->sz_line,
			&img->end);
	if (!img->addr)
		exit_with_error(data, "mlx_get_data_addr", 1);
	img->size.x = sz_x;
	img->size.y = sz_y;
}

void	safe_mlx_xpm_to_img(t_cub *data, t_img_d *img, char *f_name, t_v2i *sz)
{
	img->img_p = mlx_xpm_file_to_image(data->mlx, f_name, &sz->x, &sz->y);
	if (!img->img_p)
		exit_with_error(data, "mlx_xpm_file_to_image", 1);
	img->addr = mlx_get_data_addr(img->img_p, &img->bpp,
			&img->sz_line, &img->end);
	if (!img->addr)
		exit_with_error(data, "mlx_get_data_addr", 1);
}
