/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:42:05 by lde-medi          #+#    #+#             */
/*   Updated: 2025/01/15 20:26:47 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*get_word(char	*s, char c, int	*j);
static int	count_words(char	*s, char c);
static void	free_split(char	**arr, int i);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**split;

	if (!s)
		return (NULL);
	words = count_words((char *)s, c);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		split[i] = get_word((char *)s, c, &j);
		if (!split[i])
		{
			free_split(split, i);
			return (NULL);
		}
		i++;
	}
	split[i] = 0;
	return (split);
}

static void	free_split(char	**arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static char	*get_word(char	*s, char c, int	*j)
{
	int		i;
	int		len;
	char	*word;

	while (s[*j] == c)
		(*j)++;
	i = *j;
	while (s[i] != c && s[i])
		i++;
	len = i - *j;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[*j];
		i++;
		(*j)++;
	}
	word[i] = '\0';
	return (word);
}

static int	count_words(char	*s, char c)
{
	int	words;
	int	i;
	int	w_start;

	i = 0;
	words = 0;
	w_start = 0;
	while (s[i])
	{
		if (s[i] == c)
			w_start = 0;
		else if (w_start == 0 && s[i] != c)
		{
			words++;
			w_start = 1;
		}
		i++;
	}
	return (words);
}
