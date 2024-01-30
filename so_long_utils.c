/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:23:25 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/09 10:23:26 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_game *game, char *file_name)
{
    game->map.full = 0;
    game->map.rows = 0;
    game->map.columns = 0;
    game->map.collectible = 0;
    game->map.exit = 0;
    game->map.player = 0;
    game->position.x = 0;
    game->position.y = 0;
    game->player_up = 0;
    game->player_down = 0;
    game->player_left = 0;
    game->player_right = 0;
    game->img_width = 0;
    game->img_height = 0;
    if (!file_name)
    {
        ft_printf("%s", "Error\nThe Map");
        return ;
    }
    game->mlx = 0;
}

/*close the window with the escape button 41 = escape*/
int key_hook(int key, void* param)
{
    if(key == ESC)
        mlx_mouse_hide(param);
    //if(key == 4) // 4 = a
     //   mlx_mouse_hide(param);
    return (0);
}

/*0 is when we trigger the close of the window (by clicking the cross for example)*/
int window_hook(int event, void* param)
{
    if(event == 0)
        mlx_loop_end(param);
    return (0);
}

int img_banner(void* mlx, void* win, int img_width, int img_height)
{
    void* img = mlx_png_file_to_image(mlx, "assets/textures/background/banner/Banner_Vertical.png", &img_width, &img_height);
    mlx_put_image_to_window(mlx, win, img, 15, 1);
    mlx_string_put(mlx, win, 150, 10, 0xFFFFFFFF, "this is my text");

    
    mlx_loop(mlx);
    mlx_destroy_image(mlx, img);
    return (0);
}
