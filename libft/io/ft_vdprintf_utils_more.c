/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf_utils_more.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:57:49 by lde-medi          #+#    #+#             */
/*   Updated: 2025/10/23 00:04:31 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	init_pf_buf(t_pf_data	*data, char	*str)
{
	if (!str)
		return (0);
	ft_bzero(data, sizeof(t_pf_data));
	data->buf = ft_calloc((PRINTF_BUF + 1), sizeof(char));
	if (!data->buf)
		return (0);
	data->buf_sz = PRINTF_BUF + 1;
	return (1);
}

int	w_ptr_to_b(t_pf_data *data, uintptr_t nbr, char	*base)
{
	int		i;
	char	output[35];

	if (nbr == 0)
		return (w_str_to_b(data, "(nil)"));
	i = 0;
	while (nbr > 0)
	{
		output[i++] = base[nbr % 16];
		nbr /= 16;
	}
	output[i] = '\0';
	if (!w_str_to_b(data, "0x"))
		return (0);
	if (!r_w_str_to_b(data, output, i))
		return (0);
	return (1);
}

int	w_nb_to_b(t_pf_data	*data, int nb)
{
	char	output[12];
	int		len;
	int		is_neg;

	len = 0;
	is_neg = 0;
	if (nb == -2147483648)
		return (w_str_to_b(data, "-2147483648"));
	if (nb < 0)
	{
		is_neg++;
		nb = -nb;
	}
	if (nb == 0)
		return (w_ch_to_b(data, '0'));
	while (nb > 0)
	{
		output[len++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (is_neg)
		if (!w_ch_to_b(data, '-'))
			return (0);
	return (r_w_str_to_b(data, output, len));
}
