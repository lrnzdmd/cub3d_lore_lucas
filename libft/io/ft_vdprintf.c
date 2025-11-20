/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 07:58:48 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/13 04:48:50 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_vdprintf(int fd, const char *str, va_list *ap)
{
	t_pf_data	data;
	int			i;

	if (!init_pf_buf(&data, (char *)str))
		return (-1);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (!convert(&data, str[i + 1], ap))
				return (-1);
			i++;
		}
		else
		{
			if (!w_ch_to_b(&data, str[i]))
				return (-1);
		}
	}
	i = write(fd, data.buf, data.buf_len);
	free(data.buf);
	return (data.buf_len);
}

int	convert(t_pf_data	*data, char c, va_list *args)
{
	if (c == 'c')
		return (w_ch_to_b(data, va_arg(*args, int)));
	else if (c == '%')
		return (w_ch_to_b(data, '%'));
	else if (c == 's')
		return (w_str_to_b(data, va_arg(*args, char *)));
	else if (c == 'p')
		return (w_ptr_to_b(data, (uintptr_t)va_arg(*args, void *), LC_HX));
	else if (c == 'd' || c == 'i')
		return (w_nb_to_b(data, va_arg(*args, int)));
	else if (c == 'u')
		return (w_uint_to_b(data, va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (w_hexa_to_b(data, va_arg(*args, unsigned int), LC_HX));
	else if (c == 'X')
		return (w_hexa_to_b(data, va_arg(*args, unsigned int), UC_HX));
	else
	{
		if (!w_ch_to_b(data, '%'))
			return (0);
		if (!w_ch_to_b(data, c))
			return (0);
	}
	return (1);
}
