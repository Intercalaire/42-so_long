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
int extention_file(char *file_name)
{
	char *extension;
	extension = ft_strrchr(file_name, '.');

	if (!extension || ft_strlen(extension) != 4)
		return (1);
	if ((extension[0] == '.') && (extension[1] == 'b') && (extension[2] == 'e') && (extension[3] == 'r'))
	{
		return (0);
	}
	ft_printf("%s", "Error\nInvalid map, not a .ber file");
	return (1);
}

int init_map(t_game *game, char *file_name)
{
	int fd;
	unsigned int len_line;
	char *line;

	if (extention_file(file_name) == 1)
		return (1);
	fd = open(file_name, O_RDONLY);
	len_line = row_count(game, file_name);
	while (1)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) != len_line)
		{
			ft_printf("%s", "Error\nnot rectangulare");
		}
		if (!line)
			return (0);
		if (line[0] == '\n')
		{
			ft_printf("%s", "Error\nInvalid map, empty line");
			return (1);
		}
		how_many_inside(game, line);
		game->map.columns++;
		free(line);
	}
	game->map.full = &file_name;
	return (0);
}

void clear_map(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.rows)
	{
		free(game->map.full[i]);
		i++;
	}
	free(game->map.full);
}

int row_count(t_game *game, char *file_name)
{
	int i;

	i = 0;
	while (file_name[i] || file_name[i] != '\n')
	{
		i++;
		game->map.rows++;
	}
	game->map.rows++;
	return (i);
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
		else if (line[i] == '1' || line[i] == '0')
		return ;
		else
		{
			free(line);
			game->map.player++;
			ft_printf("%s", "map content is invalid");
			break ;
		}
		i++;
	}
}
