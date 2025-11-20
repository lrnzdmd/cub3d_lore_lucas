/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:18:01 by lde-medi          #+#    #+#             */
/*   Updated: 2025/10/28 04:11:30 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_ternop(bool	cond, void	*case_true, void *case_false)
{
	if (cond)
		return (case_true);
	else
		return (case_false);
}

int	ft_ternop_int(bool	cond, int case_true, int case_false)
{
	if (cond)
		return (case_true);
	else
		return (case_false);
}
