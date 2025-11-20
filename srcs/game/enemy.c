/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 05:08:50 by lorenzo           #+#    #+#             */
/*   Updated: 2025/11/20 05:29:21 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update_enemy_states(t_cub *data, t_ent	*enemy, int	enm_n)
{
	int	i;

	i = -1;
	while (++i < enm_n)
	{
		enemy[i].data.st_timer -= data->d_time;
		if (enemy[i].data.st_timer > 0)
			continue ;
		if (rand() % 2 == 0)
			enemy[i].data.state = IDLE;
		else
			enemy[i].data.state = PATROL;
		enemy[i].data.st_timer = ENM_AI_TIMER;
	}
}

void	enemy_action(t_cub *data, t_ent	*enemy, int	enm_n)
{
	int	i;

	i = -1;
	(void)data;
	while (++i < enm_n)
	{
		if (enemy[i].data.state == IDLE)
			ft_printf("%d is IDLE!\n", i);
		if (enemy[i].data.state == PATROL)
			ft_printf("%d is PATROLLING!\n", i);
	}
}