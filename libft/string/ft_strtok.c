/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 04:50:22 by lde-medi          #+#    #+#             */
/*   Updated: 2025/09/16 19:40:48 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*skip_delimiters(char *str, const char *sep);
static char	*find_token_end(char *str, const char *sep);

char	*ft_strtok(char *str, const char *sep)
{
	static char	*save = NULL;
	char		*start;

	if (str != NULL)
		save = str;
	if (save == NULL || *save == '\0')
		return (NULL);
	save = skip_delimiters(save, sep);
	if (*save == '\0')
		return (NULL);
	start = save;
	save = find_token_end(save, sep);
	return (start);
}

static char	*skip_delimiters(char *str, const char *sep)
{
	while (*str && ft_strchr(sep, *str))
		str++;
	return (str);
}

static char	*find_token_end(char *str, const char *sep)
{
	while (*str && !ft_strchr(sep, *str))
		str++;
	if (*str)
	{
		*str = '\0';
		str++;
	}
	else
		str = NULL;
	return (str);
}
