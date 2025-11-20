/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:22:25 by lde-medi          #+#    #+#             */
/*   Updated: 2025/01/14 19:14:26 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	digits_count(int n);

char	*ft_itoa(int n)
{
	int		len;
	int		is_neg;
	char	*output;

	is_neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		is_neg++;
		n = -n;
	}
	len = digits_count(n) + is_neg;
	output = ft_calloc((len + 1), sizeof(char));
	if (!output)
		return (NULL);
	while (len-- > 0)
	{
		output[len] = '0' + (n % 10);
		n /= 10;
		if (is_neg && len == 0)
			output[len] = '-';
	}
	return (output);
}

static int	digits_count(int n)
{
	int	digits;

	digits = 1;
	while (n > 9)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}
