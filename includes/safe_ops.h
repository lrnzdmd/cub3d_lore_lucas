/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_ops.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 01:42:59 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 04:41:13 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFE_OPS_H
# define SAFE_OPS_H

# include <types.h>

char	*safe_strdup(t_cub *data, const char *src);
char	**safe_split(t_cub *data, const char *s, char c);
char	*safe_strtrim(t_cub *data, const char	*src, const char *set);
char	*safe_substr(t_cub *data,
			const char *src, unsigned int start, size_t len);
char	*safe_substr_free(t_cub *data,
			char *src, unsigned int start, size_t len);
char	*safe_itoa(t_cub *data, int nb);
void	*safe_calloc(t_cub *data, size_t count, size_t size);
void	*safe_realloc(t_cub *data,
			void *orig_ptr, size_t old_size, size_t new_size);
void	safe_append_lst(t_cub	*data, t_list	**lst, void	*content);
char	*safe_strjoin(t_cub *data, const char *s1, const char *s2);
void	*safe_mlx_init(t_cub	*data);
void	*safe_mlx_new_window(t_cub	*data, int sz_x, int sz_y, char	*title);
void	safe_mlx_new_img(t_cub	*data, t_img_d	*img, int sz_x, int sz_y);
void	safe_mlx_free_img(void *mlx, void *img);
void	safe_mlx_xpm_to_img(t_cub *data, t_img_d *img, char *f_name, t_v2i *sz);

#endif
