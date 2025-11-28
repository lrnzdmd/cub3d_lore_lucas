/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:49:10 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/28 08:04:16 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_array(char	***arr)
{
	int	i;

	i = -1;
	if (*arr)
	{
		while ((*arr)[++i])
			free((*arr)[i]);
		free(*arr);
		*arr = NULL;
	}
}

void	free_list(t_list	**lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_multifree(2, &tmp->content, &tmp);
	}
}

void	free_gfx_data(t_cub	*data)
{
	void	*mlx;
	t_gfx	*gfx;

	mlx = data->mlx;
	gfx = &data->gfx;
	safe_mlx_free_img(mlx, gfx->fr_bf.img_p);
	safe_mlx_free_img(mlx, gfx->m_map.img_p);
	safe_mlx_free_img(mlx, gfx->txt.wall.n.img_p);
	safe_mlx_free_img(mlx, gfx->txt.wall.s.img_p);
	safe_mlx_free_img(mlx, gfx->txt.wall.w.img_p);
	safe_mlx_free_img(mlx, gfx->txt.wall.e.img_p);
	safe_mlx_free_img(mlx, gfx->txt.wall.dr.img_p);
	if (gfx->txt.sprts.enemy.attack.frame)
	{
		safe_mlx_free_img(mlx, gfx->txt.sprts.enemy.attack.frame[0].img_p);
		safe_mlx_free_img(mlx, gfx->txt.sprts.enemy.attack.frame[1].img_p);
	}
	if (gfx->txt.sprts.enemy.walk.frame)
	{
		safe_mlx_free_img(mlx, gfx->txt.sprts.enemy.walk.frame[0].img_p);
		safe_mlx_free_img(mlx, gfx->txt.sprts.enemy.walk.frame[1].img_p);
	}
	if (gfx->txt.sprts.enemy.dead.frame)
		safe_mlx_free_img(mlx, gfx->txt.sprts.enemy.dead.frame[0].img_p);
	if (gfx->txt.sprts.enemy.idle.frame)
		safe_mlx_free_img(mlx, gfx->txt.sprts.enemy.idle.frame[0].img_p);
	safe_mlx_free_img(mlx, gfx->txt.sprts.gun[0].img_p);
	safe_mlx_free_img(mlx, gfx->txt.sprts.gun[1].img_p);
	ft_multifree(6, &gfx->txt.sprts.enemy.dead.frame, &gfx->txt.sprts.enemy.idle.frame, &gfx->txt.sprts.enemy.attack.frame, &gfx->txt.sprts.enemy.walk.frame, &data->gman.enemies, &data->gfx.zbuffer);
}

void	free_tmp_pointers(t_cub	*data)
{
	t_tmp	*tmp;

	tmp = &data->tmp;
	if (tmp->fd != -1)
	{
		ft_get_next_line(tmp->fd, GNL_FLUSH);
		close(tmp->fd);
	}
	if (tmp->arr)
		free_array(&tmp->arr);
	if (tmp->lst)
		free_list(&tmp->lst);
	ft_multifree(3, &tmp->gnl, &tmp->str_1, &tmp->str_2);
}
