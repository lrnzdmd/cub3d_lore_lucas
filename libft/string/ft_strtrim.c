/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:26:37 by lde-medi          #+#    #+#             */
/*   Updated: 2025/01/14 01:56:34 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	trimmed_len(char const	*s1, char const	*set, int *i, int *j);
static int	is_in_charset(char c, char	const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	len = trimmed_len(s1, set, &i, &j);
	output = (char *)ft_calloc((len + 1), sizeof(char));
	if (!output)
		return (NULL);
	j = 0;
	while (j < len)
		output[j++] = s1[i++];
	return (output);
}

static int	trimmed_len(char const	*s1, char const *set, int *i, int *j)
{
	*j = ft_strlen(s1) - 1;
	while (is_in_charset(s1[*i], set))
		(*i)++;
	while (*j > *i && is_in_charset(s1[*j], set))
		(*j)--;
	if (*j < *i)
		return (0);
	else
		return (*j - *i + 1);
}

static int	is_in_charset(char c, char	const *set)
{
	int	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
