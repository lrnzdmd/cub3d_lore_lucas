/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:08:31 by lde-medi          #+#    #+#             */
/*   Updated: 2024/12/05 18:36:14 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*p;

	if (!lst)
		return (0);
	p = lst;
	size = 0;
	while (p != NULL)
	{
		size++;
		p = p->next;
	}
	return (size);
}
