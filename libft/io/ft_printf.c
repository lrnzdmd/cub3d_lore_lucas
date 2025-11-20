/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 03:23:09 by lde-medi          #+#    #+#             */
/*   Updated: 2025/09/14 22:57:44 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_printf(const char	*fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = ft_vdprintf(1, fmt, &ap);
	va_end(ap);
	return (len);
}
