/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:54:56 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/24 19:57:27 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_wall(void *mlx, void *mlx_window, char **tab_map)
{
	int		width;
	int		height;
	void	*img_wall;
	int		i;
	int		j;

	img_wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &width, &height);
	if (!img_wall)
	{
		ft_putstr_fd("Error\n Could not load image\n", 2);
		return ;
	}
	i = -1;
	while (tab_map[++i])
	{
		j = -1;
		while (tab_map[i][++j])
		{
			if (tab_map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_window, img_wall,
					j * 48, i * 48);
		}
	}
}

void	create_ground(void *mlx, void *mlx_window, char **tab_map)
{
	int		width;
	int		height;
	void	*img_ground;
	int		i;
	int		j;

	img_ground = mlx_xpm_file_to_image(mlx, "./images/ground.xpm",
			&width, &height);
	if (!img_ground)
	{
		ft_putstr_fd("Error\n Could not load image\n", 2);
		return ;
	}
	i = -1;
	while (tab_map[++i])
	{
		j = -1;
		while (tab_map[i][++j])
		{
			if (tab_map[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_window, img_ground,
					j * 48, i * 48);
		}
	}
}

void	create_p(void *mlx, void *mlx_window, char **tab_map)
{
	int		width;
	int		height;
	void	*img_pigeon;
	int		i;
	int		j;

	img_pigeon = mlx_xpm_file_to_image(mlx, "./images/pigeon.xpm",
			&width, &height);
	if (!img_pigeon)
	{
		ft_putstr_fd("Error\n Could not load image\n", 2);
		return ;
	}
	i = -1;
	while (tab_map[++i])
	{
		j = -1;
		while (tab_map[i][++j])
		{
			if (tab_map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_window, img_pigeon,
					j * 48, i * 48);
		}
	}
}

void	create_c(void *mlx, void *mlx_window, char **tab_map)
{
	int		width;
	int		height;
	void	*img_collectible;
	int		i;
	int		j;

	img_collectible = mlx_xpm_file_to_image(mlx, "./images/collectible.xpm",
			&width, &height);
	if (!img_collectible)
	{
		ft_putstr_fd("Error\n Could not load image\n", 2);
		return ;
	}
	i = -1;
	while (tab_map[++i])
	{
		j = -1;
		while (tab_map[i][++j])
		{
			if (tab_map[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_window, img_collectible,
					j * 48, i * 48);
		}
	}
}

void	create_e(void *mlx, void *mlx_window, char **tab_map)
{
	int		width;
	int		height;
	void	*img_exit;
	int		i;
	int		j;

	img_exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm",
			&width, &height);
	if (!img_exit)
	{
		ft_putstr_fd("Error\n Could not load image\n", 2);
		return ;
	}
	i = -1;
	while (tab_map[++i])
	{
		j = -1;
		while (tab_map[i][++j])
		{
			if (tab_map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_window, img_exit,
					j * 48, i * 48);
		}
	}
}
