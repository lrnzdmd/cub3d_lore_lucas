/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 05:48:51 by lde-medi          #+#    #+#             */
/*   Updated: 2025/10/22 23:58:13 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	w_uint_to_b(t_pf_data	*data, unsigned int nb)
{
	char	output[12];
	int		len;

	len = 0;
	if (nb == 0)
	{
		if (!w_ch_to_b(data, '0'))
			return (0);
		else
			return (1);
	}
	while (nb > 0)
	{
		output[len++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (!r_w_str_to_b(data, output, len))
		return (0);
	return (1);
}

int	r_w_str_to_b(t_pf_data	*data, char	*str, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
		if (!w_ch_to_b(data, str[i--]))
			return (0);
	return (1);
}

int	w_hexa_to_b(t_pf_data *data, unsigned int nbr, char	*base)
{
	int		i;
	char	output[35];

	i = 0;
	if (nbr == 0)
	{
		if (!w_ch_to_b(data, '0'))
			return (0);
		else
			return (1);
	}
	while (nbr > 0)
	{
		output[i++] = base[nbr % 16];
		nbr /= 16;
	}
	output[i] = '\0';
	if (!r_w_str_to_b(data, output, i))
		return (0);
	return (1);
}

int	w_ch_to_b(t_pf_data *data, int c)
{
	char	*tmp;
	size_t	new_sz;

	if (data->buf_i + 1 >= (int)data->buf_sz)
	{
		new_sz = data->buf_sz + PRINTF_BUF;
		tmp = ft_realloc(data->buf, data->buf_sz, new_sz);
		if (!tmp)
		{
			free(data->buf);
			return (0);
		}
		data->buf = tmp;
		data->buf_sz = new_sz;
	}
	data->buf[data->buf_i] = (char)c;
	data->buf_i++;
	data->buf_len++;
	data->buf[data->buf_i] = '\0';
	return (1);
}

int	w_str_to_b(t_pf_data	*data, char	*str)
{
	int		str_l;
	char	*tmp;
	size_t	new_sz;

	if (!str)
		str = "(null)";
	str_l = ft_strlen(str);
	while (data->buf_len + str_l >= (int)data->buf_sz - 1)
	{
		new_sz = data->buf_sz + str_l + PRINTF_BUF;
		tmp = ft_realloc(data->buf, data->buf_sz, new_sz);
		if (!tmp)
		{
			free(data->buf);
			return (0);
		}
		data->buf = tmp;
		data->buf_sz = new_sz;
	}
	str_l = -1;
	while (str[++str_l])
		data->buf[data->buf_i++] = str[str_l];
	data->buf_len += str_l;
	data->buf[data->buf_i] = '\0';
	return (1);
}
