/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medio@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:49:10 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/29 03:52:21 by lde-medi         ###   ########.fr       */
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

void	clean_anim(void *mlx, t_anim *anim)
{
	int	i;

	i = -1;
	while (++i < anim->frm_n)
		safe_mlx_free_img(mlx, anim->frame[i].img_p);
	ft_multifree(1, &anim->frame);
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
	if (gfx->txt.sprts.plyr.shoot.frame)
		clean_anim(mlx, &gfx->txt.sprts.plyr.shoot);
	if (gfx->txt.sprts.plyr.reload.frame)
		clean_anim(mlx, &gfx->txt.sprts.plyr.reload);
	if (gfx->txt.sprts.plyr.idle.frame)
		clean_anim(mlx, &gfx->txt.sprts.plyr.idle);
	if (gfx->txt.sprts.enemy.attack.frame)
		clean_anim(mlx, &gfx->txt.sprts.enemy.attack);
	if (gfx->txt.sprts.enemy.walk.frame)
		clean_anim(mlx, &gfx->txt.sprts.enemy.walk);
	if (gfx->txt.sprts.enemy.dead.frame)
		clean_anim(mlx, &gfx->txt.sprts.enemy.dead);
	if (gfx->txt.sprts.enemy.idle.frame)
		clean_anim(mlx, &gfx->txt.sprts.enemy.idle);
	ft_multifree(2, &data->gman.enemies,
		&data->gfx.zbuffer);
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
