/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:36:03 by lde-medi          #+#    #+#             */
/*   Updated: 2024/12/02 03:39:18 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	is_whitespace(char c);

int	ft_atoi(const char	*str)
{
	int		i;
	char	sign;
	int		output;

	i = 0;
	sign = '\0';
	output = 0;
	while (is_whitespace(str[i]))
		i++;
	if ((str[i] == '+' || str[i] == '-') && sign == '\0')
	{
		sign = str[i];
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		output = (output * 10) + (str[i] - '0');
		i++;
	}
	if (sign == '-')
		output = -output;
	return (output);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}
