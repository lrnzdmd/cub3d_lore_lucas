/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 03:04:39 by lde-medi          #+#    #+#             */
/*   Updated: 2025/09/13 03:05:19 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (!ptr)
		return (ft_calloc(new_size, 1));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size <= old_size)
		return (ptr);
	new_ptr = ft_calloc(new_size, 1);
	if (!new_ptr)
		return (NULL);
	copy_size = old_size;
	if (new_size < old_size)
		copy_size = new_size;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}
