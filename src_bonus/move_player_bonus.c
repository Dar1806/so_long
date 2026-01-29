/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:45:10 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/29 13:53:33 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_left(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P' && (g->map[i][j - 1] == '0'
					|| g->map[i][j - 1] == 'C'
					|| (g->map[i][j - 1] == 'E' && valid_map_check_c(g->map))
					|| (g->map[i][j - 1] == 'N' && destroy_w_bonus(g))))
			{
				g->map[i][j - 1] = 'P';
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_pigeon_left, (j - 1) * 48, i * 48);
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_ground, j * 48, i * 48);
				g->map[i][j] = '0';
				return (1);
			}
		}
	}
	return (0);
}

int	move_right(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P' && (g->map[i][j + 1] == '0'
					|| g->map[i][j + 1] == 'C'
					|| (g->map[i][j + 1] == 'E' && valid_map_check_c(g->map))
					|| (g->map[i][j + 1] == 'N' && destroy_w_bonus(g))))
			{
				g->map[i][j + 1] = 'P';
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_pigeon_right, (j + 1) * 48, i * 48);
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_ground, j * 48, i * 48);
				g->map[i][j] = '0';
				return (1);
			}
		}
	}
	return (0);
}

int	move_up(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P' && (g->map[i - 1][j] == '0'
				|| g->map[i - 1][j] == 'C'
				|| (g->map[i - 1][j] == 'E' && valid_map_check_c(g->map))
				|| (g->map[i - 1][j] == 'N' && destroy_w_bonus(g))))
			{
				g->map[i - 1][j] = 'P';
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_pigeon_left, j * 48, (i - 1) * 48);
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_ground, j * 48, i * 48);
				g->map[i][j] = '0';
				return (1);
			}
		}
	}
	return (0);
}

int	move_down(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P' && (g->map[i + 1][j] == '0'
				|| g->map[i + 1][j] == 'C'
				|| (g->map[i + 1][j] == 'E' && valid_map_check_c(g->map))
				|| (g->map[i + 1][j] == 'N' && destroy_w_bonus(g))))
			{
				g->map[i + 1][j] = 'P';
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_pigeon_left, j * 48, (i + 1) * 48);
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_ground, j * 48, i * 48);
				g->map[i][j] = '0';
				return (1);
			}
		}
	}
	return (0);
}
