/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:29:59 by lde-medi          #+#    #+#             */
/*   Updated: 2025/01/16 00:50:44 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*last_node;

	if (!lst || !f || !del)
		return (NULL);
	last_node = ft_lstnew(NULL);
	if (!last_node)
		return (NULL);
	last_node->content = f(lst->content);
	first = last_node;
	lst = lst->next;
	while (lst)
	{
		last_node->next = ft_lstnew(NULL);
		if (!last_node->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		last_node->next->content = f(lst->content);
		last_node = last_node->next;
		lst = lst->next;
	}
	last_node->next = NULL;
	return (first);
}
