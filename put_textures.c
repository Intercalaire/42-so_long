/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:46:13 by vgodart           #+#    #+#             */
/*   Updated: 2024/02/20 13:46:15 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_walls(t_texture *texture, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, texture->wall, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	put_exit(t_texture *texture, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, texture->exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void put_collectibles(t_texture *texture, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, texture->collectible, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void put_player(t_texture *texture, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, texture->player, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	put_backgrounds(t_texture *texture, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, texture->background, x * 32, y * 32);
			x++;
		}
		y++;
	}
}