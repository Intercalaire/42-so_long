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

	if (argc != 2)
	{
		ft_printf("%s", "Error\nThis programe take 1 argument .ber");
		return (0);
	}
    game = malloc(sizeof(t_game));
    init_game(game, argv[1]);
    if (init_map(game, argv[1]) == 1)
        return (1);
    if (parsing(game) == 1)
        return (0);
    void* mlx = mlx_init();
    void* win = mlx_new_window(mlx, 500, 400, "Hello world!");

    int img_width;
    int img_height;

    img_width = 150;
    img_height = 10;
    mlx_on_event(mlx, win, MLX_KEYDOWN, key_hook, mlx);
    mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook, mlx);
    img_banner(mlx, win, img_width, img_height);
    mlx_loop(mlx);

    // do not forget to destroy the image, otherwise the MacroLibX will yell at you !
    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
}

void	load_textures(t_texture *texture, t_data *data)
{
	int	*x;
	int	*y;

    x = malloc(sizeof(int));
	y = malloc(sizeof(int));
}