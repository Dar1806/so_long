/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:54:56 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/26 23:42:18 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_wall(t_game *g)
{
	int	i;
	int	j;

	g->img_wall = mlx_xpm_file_to_image(g->mlx,
			"./images/wall.xpm", &g->width, &g->height);
	if (!g->img_wall)
	{
		ft_putstr_fd("Error\n Could not load image\n", 2);
		destroy_w(g);
		return ;
	}
	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_wall, j * 48, i * 48);
		}
	}
}

void	create_ground(t_game *g)
{
	int	i;
	int	j;

	g->img_ground = mlx_xpm_file_to_image(g->mlx,
			"./images/ground.xpm", &g->width, &g->height);
	if (!g->img_ground)
	{
		ft_putstr_fd("Error\n Could not load image\n", 2);
		destroy_w(g);
		return ;
	}
	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == '0')
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_ground, j * 48, i * 48);
		}
	}
}

void	create_p(t_game *g)
{
	int	i;
	int	j;

	g->img_pigeon_left = mlx_xpm_file_to_image(g->mlx,
			"./images/pigeon_left.xpm", &g->width, &g->height);
	g->img_pigeon_right = mlx_xpm_file_to_image(g->mlx,
			"./images/pigeon_right.xpm", &g->width, &g->height);
	if (!g->img_pigeon_left || !g->img_pigeon_right)
	{
		ft_putstr_fd("Error\n Could not load image\n", 2);
		destroy_w(g);
		return ;
	}
	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_pigeon_left, j * 48, i * 48);
		}
	}
}

void	create_c(t_game *g)
{
	int	i;
	int	j;

	g->img_collectible = mlx_xpm_file_to_image(g->mlx,
			"./images/collectible.xpm", &g->width, &g->height);
	if (!g->img_collectible)
	{
		ft_putstr_fd("Error\n Could not load image\n", 2);
		destroy_w(g);
		return ;
	}
	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_collectible, j * 48, i * 48);
		}
	}
}

void	create_e(t_game *g)
{
	int	i;
	int	j;

	g->img_exit = mlx_xpm_file_to_image(g->mlx, "./images/exit.xpm",
			&g->width, &g->height);
	if (!g->img_exit)
	{
		ft_putstr_fd("Error\n Could not load image\n", 2);
		destroy_w(g);
		return ;
	}
	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_exit, j * 48, i * 48);
		}
	}
}
