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
    game->texture->collectible = (t_texture *)NULL;
    game->texture->exit = (t_texture *)NULL;
    game->texture->player = (t_texture *)NULL;
    game->texture->background = (t_texture *)NULL;
    if (!file_name)
    {
        error_message("Error\nThe Map", game);
        return ;
    }
    game->mlx_win = 0;
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

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
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
