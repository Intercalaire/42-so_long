/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:38:16 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/15 13:38:18 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*initialiser la map, */

/*look the extention_file if this is a .ber*/
int extention_file(t_game *game, char *file_name)
{
	char *extension;
	extension = ft_strrchr(file_name, '.');

	if (!extension || ft_strlen(extension) != 4)
		return (1);
	if ((extension[0] == '.') && (extension[1] == 'b') && (extension[2] == 'e') && (extension[3] == 'r'))
	{
		return (0);
	}
	error_message("Error\nInvalid map, not a .ber file", game);
	return (1);
}

int init_map(t_game *game, char *file_name)
{
	int fd;
	unsigned int len_line;
	char *line;

	game->map.full = (char **)malloc(sizeof(char *) * (9999));
	if (!game->map.full)
		return (0);
	extention_file(game, file_name);
	fd = open(file_name, O_RDONLY);
	len_line = row_count(game, file_name);
	while (1)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) != len_line)
		{
			error_message("Error\nnot rectangulare", game);
		}
		if (!line)
			return (0);
		if (line[0] == '\n')
		{
			error_message("Error\nInvalid map, empty line", game);
		}
		how_many_inside(game, line);
		game->map.rows++;
		free(line);
	}
	game->map.full = &file_name;
	return (0);
}

int row_count(t_game *game, char *file_name)
{
	int count;
	int fd;	
	char c;

	fd = open(file_name, O_RDONLY);
	count = 0;
	if (fd == -1)
	{
		error_message("Error\nFailed to open file", game);
	}

	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			break;
		count++;
		game->map.columns++;
	}

	close(fd);
	return (count);
}

void how_many_inside(t_game *game, char *line)
{
	int i;

	i = 0;
	// ft_printf("%s", line);
	while (line[i])
	{
		if (line[i] == Player)
			game->map.player++;
		if (line[i] == EXIT)
			game->map.exit++;
		if (line[i] == COLLECTIBLE)
			game->map.collectible++;
		i++;
	}
}
