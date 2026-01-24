/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:40:44 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/21 18:06:58 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	create_wall(void *mlx, void *mlx_window, t_game *game)
{
	int		width;
	int		height;
	void	*img_wall;
	int		i;
	int		j;
	
	img_wall = mlx_xpm_file_to_image(mlx, "./maps/wall.xpm", &width, &height);
	if (!img_wall)
	{
		ft_putstr_fd("Error: Could not load image\n", 2);
		return ;
	}
	i = -1;
	while (game->map_mlx[++i])
	{
		j = -1;
		while (game->map_mlx[i][++j])
		{
			if (game->map_mlx[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_window, img_wall, j * 48, i * 48);
		}
	}
}

void	create_ground(void *mlx, void *mlx_window, t_game *game)
{
	int		width;
	int		height;
	void	*img_ground;
	int		i;
	int		j;
	
	img_ground = mlx_xpm_file_to_image(mlx, "./maps/ground.xpm", &width, &height);
	if (!img_ground)
	{
		ft_putstr_fd("Error: Could not load image\n", 2);
		return ;
	}
	i = -1;
	while (game->map_mlx[++i])
	{
		j = -1;
		while (game->map_mlx[i][++j])
		{
			if (game->map_mlx[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_window, img_ground, j * 48, i * 48);
		}
	}
}

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
	mlx_loop(mlx);
}
