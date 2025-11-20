/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:37:08 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/13 04:48:09 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int nb, int fd)
{
	int	r;

	if (nb == -2147483648)
	{
		r = write(fd, "-2147483648", 11);
		(void)r;
		return ;
	}
	if (nb < 0)
	{
		r = write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
	(void)r;
}
