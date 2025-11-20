/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multifree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:16:02 by lde-medi          #+#    #+#             */
/*   Updated: 2025/10/15 04:40:09 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief frees n pointers and set them to NULL.
 * * @param n the amount of pointers to be freed.
 * @param s2 the mem address of the pointers to free. 
 */
void	ft_multifree(int n, ...)
{
	void	**ptr;
	int		i;
	va_list	ap;

	if (n < 1)
		return ;
	i = 0;
	va_start(ap, n);
	while (i < n)
	{
		ptr = va_arg(ap, void **);
		if (*ptr)
			free(*ptr);
		*ptr = NULL;
		i++;
	}
	va_end(ap);
}
