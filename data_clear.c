/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:17:22 by vgodart           #+#    #+#             */
/*   Updated: 2024/02/15 12:17:23 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static void	game_destroy(t_game *game)
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

void	data_clear(t_game *game)
{
	if (game != 0)
	{
		if (game->texture->collectible != 0)
			mlx_destroy_image(game->mlx, game->texture->collectible);
		if (game->texture->exit != 0)
			mlx_destroy_image(game->mlx, game->texture->exit);
		if (game->texture->player != 0)
			mlx_destroy_image(game->mlx, game->texture->player);
		if (game->texture->background != 0)
			mlx_destroy_image(game->mlx, game->texture->background);
		if (game->mlx_win != 0 && game->mlx != 0)
		{
			mlx_destroy_window(game->mlx, game->mlx_win);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game != 0)
			game_destroy(game);
		free(game);
	}
}