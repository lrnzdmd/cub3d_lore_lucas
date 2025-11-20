/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:43:07 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/12 00:12:26 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	check_file_openable(t_cub	*data, char	*filename);

void	validate_args(t_cub	*data, int ac, char	**av)
{
	if (ac != 2)
		exit_with_error(data, ERR_USAGE, 1);
	if (!check_file_extension(av[1], ".cub"))
		exit_with_error(data, ERR_MAP_EXT, 1);
	check_file_openable(data, av[1]);
}

static void	check_file_openable(t_cub	*data, char	*filename)
{
	int	fd;

	fd = open(filename, O_RDONLY | __O_DIRECTORY);
	if (fd != -1)
		exit_with_error(data, ERR_CUB_ISDIR, 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_with_strerror(data, filename, 1);
	close(fd);
}

bool	check_file_extension(char	*filename, char *extension)
{
	int	n_len;

	if (!filename || !*filename)
		return (false);
	n_len = ft_strlen(filename);
	if (n_len <= 4 || ft_strcmp(&filename[n_len - 4], extension) != 0)
		return (false);
	return (true);
}
