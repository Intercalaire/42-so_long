/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:42:46 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/09 11:42:48 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*verifier ligne par ligne ce qui sy trouve et ensuite ajouter 1 a la valeur quon trouve sur par exemple il y a 2P sois 2 joueurs
stop pas la bonne map si pas de sortie aussi si pas de piece aussi si la salle ou son les pieces est bloquer aussi*/

int parsing(t_game *game)
{
	if ((check_rows(game) || check_columns(game) || verification_CEP(game) ) == 1)
		return (1);
	return (0);
}

int	check_rows(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map.rows)
	{
		if (game->map.full[x][0] != WALL)
		{
			ft_printf("%s", "Error\nThe Map must be surrounded by walls");
			return (1);
		}
		else if (game->map.full[x][game->map.columns - 1] != WALL)
		{
			ft_printf("%s", "Error\nThe Map must be surrounded by walls");
			return (1);
		}
		x++;
	}
	return (0);
}

int	check_columns(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.columns)
	{
		if (game->map.full[0][y] != WALL)
		{
			ft_printf("%s", "Error\nThe Map must be surrounded by walls");
			return (1);
		}
		else if (game->map.full[game->map.rows - 1][y] != WALL)
		{
			ft_printf("%s", "Error\nThe Map must be surrounded by walls");
			return (1);
		}
		y++;
	}
	return (0);
}

int	verification_CEP(t_game *game)
{
	if (game->map.collectible == 0)
	{
		ft_printf("%d", game->map.collectible);
		ft_printf("%s", "Error\nto low collectible");
		return (1);
	}
	else if (game->map.exit != 1)
	{
		ft_printf("%s", "Error\nthere is no one exit");
		return (1);
	}
	else if (game->map.player != 1)
	{
		ft_printf("%s", "Error\nthere is one player");
		return (1);
	}

	return (0);
}