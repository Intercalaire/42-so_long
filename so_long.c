/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:23:09 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/09 10:23:12 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	data_clear(game);
	exit(0);
}

int main(int argc, char **argv)
{
    t_game  *game;
    t_texture	*texture;

	if (argc != 2)
	{
		ft_printf("%s", "Error\nThis programe take 1 argument .ber");
		return (0);
	}
    texture = malloc(sizeof(t_texture));
    game = malloc(sizeof(t_game));
    init_game(game, argv[1]);
    game->mlx = mlx_init();
    void* win = mlx_new_window(game->mlx, 500, 400, "Hello world!");
    initialize_img(game, texture);
    if (init_map(game, argv[1]) == 1)
        return (1);
    if (parsing(game) == 1)
        return (0);

    int img_width;
    int img_height;

    img_width = 150;
    img_height = 10;
    mlx_on_event(game->mlx, win, MLX_KEYDOWN, key_hook, game->mlx);
    mlx_on_event(game->mlx, win, MLX_WINDOW_EVENT, window_hook, game->mlx);
    mlx_loop(game->mlx);

    // do not forget to destroy the image, otherwise the MacroLibX will yell at you !
}

void	load_textures(t_texture *texture, t_game *game)
{
	int	x;
	int	y;

    texture->wall = mlx_png_file_to_image(game->mlx,
			"./assets/textures/background/wall.png", &x, &y);
	texture->collectible = mlx_png_file_to_image(game->mlx,
			"./assets/textures/treasure/collectible.png", &x, &y);
	texture->exit = mlx_png_file_to_image(game->mlx,
			"./assets/textures/exit/exit.png", &x, &y);
	texture->player = mlx_png_file_to_image(game->mlx,
			"./assets/textures/player/player.png", &x, &y);
	texture->background = mlx_png_file_to_image(game->mlx,
			"./assets/textures/background/flatsize.png", &x, &y);
}