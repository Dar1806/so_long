/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 01:12:22 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/29 16:19:26 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_enemy(t_game *g)
{
	int	i;
	int	j;

	g->img_enemy_left = mlx_xpm_file_to_image(g->mlx,
			"./images/cat_left.xpm", &g->width, &g->height);
	g->img_enemy_right = mlx_xpm_file_to_image(g->mlx,
			"./images/cat_right.xpm", &g->width, &g->height);
	if (!g->img_enemy_left || !g->img_enemy_right)
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
			if (g->map[i][j] == 'N')
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_enemy_left, j * 48, i * 48);
		}
	}
}

void	locate_enemy_p(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'N')
			{
				g->enemy_i = i;
				g->enemy_j = j;
			}
			if (g->map[i][j] == 'P')
			{
				g->player_i = i;
				g->player_j = j;
			}
		}
	}
}

int	destroy_w_bonus(t_game *g)
{
	ft_putstr_fd("Game Over! You were caught by the enemy!\n", 1);
	free_all(g);
	exit(0);
	return (1);
}
