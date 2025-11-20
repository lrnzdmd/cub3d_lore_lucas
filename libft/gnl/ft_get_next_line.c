/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:39:23 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/13 04:45:20 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_get_next_line(int fd, int flush)
{
	static char		*gnl[1024];
	ssize_t			bytes_read;
	char			*output;
	char			buffer[BUFFER_SIZE + 1];

	if (fd >= 0 && fd <= 1024)
		gnl[fd] = gnl_init_store(fd, &gnl[fd]);
	if (!gnl[fd])
		return (NULL);
	while (!ft_strchr(gnl[fd], '\n') && flush != GNL_FLUSH)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(gnl[fd]), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		gnl[fd] = gnl_add_to_store(&gnl[fd], buffer);
	}
	output = gnl_extract_line(&gnl[fd]);
	if (!output)
		return (free(gnl[fd]), NULL);
	if (!output[0] || flush == GNL_FLUSH)
		return (ft_multifree(2, &gnl[fd], &output), NULL);
	return (output);
}

char	*gnl_init_store(int fd, char **store)
{
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	if (!*store)
		*store = ft_calloc(1, sizeof(char));
	if (!*store)
		return (NULL);
	return (*store);
}

char	*gnl_extract_line(char	**store)
{
	char	*line;
	char	*tmp;
	int		s_len;
	int		i;

	i = 0;
	s_len = ft_strlen(*store);
	while ((*store)[i] && (*store)[i] != '\n')
		i++;
	if ((*store)[i] == '\n')
		i++;
	line = ft_substr(*store, 0, i);
	if (!line)
		return (free(*store), NULL);
	tmp = ft_calloc(s_len - i + 1, sizeof(char));
	if (!tmp)
		return (free(*store), NULL);
	ft_memcpy(tmp, *store + i, s_len - i);
	free(*store);
	*store = tmp;
	return (line);
}

char	*gnl_add_to_store(char	**store, char	*buffer)
{
	char	*tmp;
	int		b_len;
	int		s_len;

	b_len = ft_strlen(buffer);
	s_len = ft_strlen(*store);
	tmp = ft_realloc(*store, s_len + 1, s_len + b_len + 1);
	if (!tmp)
		return (free(*store), NULL);
	ft_memcpy(tmp + s_len, buffer, b_len);
	tmp[s_len + b_len] = 0;
	*store = tmp;
	return (*store);
}
