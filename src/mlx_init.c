/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:40:44 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/24 18:14:44 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_create(char **tab_map)
{
	void	*mlx;
	void	*mlx_window;
	t_game	game;

	game.map_mlx = tab_map;
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "Game");
	create_ground(mlx, mlx_window, &game);
	create_wall(mlx, mlx_window, &game);
	create_p(mlx, mlx_window, &game);
	mlx_loop(mlx);
}
