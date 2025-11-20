/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:15:25 by lde-medi          #+#    #+#             */
/*   Updated: 2025/09/14 22:52:33 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_dprintf(int fd, const char	*fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = ft_vdprintf(fd, fmt, &ap);
	va_end(ap);
	return (len);
}
