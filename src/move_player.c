/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:28:07 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/26 16:39:43 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_left(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P')
			{
				if (g->map[i][j -1] == '0' || g->map[i][j -1] == 'C' || v_e(g))
				{
					g->map[i][j -1] = 'P';
					mlx_put_image_to_window(g->mlx, g->mlx_window,
						g->img_pigeon, (j -1) * 48, i * 48);
					mlx_put_image_to_window(g->mlx, g->mlx_window,
						g->img_ground, j * 48, i * 48);
					g->map[i][j] = '0';
					return (1);
				}
			}
		}
	}
	return (0);
}

int	move_right(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P')
			{
				if (g->map[i][j +1] == '0' || g->map[i][j +1] == 'C' || v_e(g))
				{
					g->map[i][j + 1] = 'P';
					mlx_put_image_to_window(g->mlx, g->mlx_window,
						g->img_pigeon, (j + 1) * 48, i * 48);
					mlx_put_image_to_window(g->mlx, g->mlx_window,
						g->img_ground, j * 48, i * 48);
					g->map[i][j] = '0';
					return (1);
				}
			}
		}
	}
	return (0);
}

int	move_up(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P')
			{
				if (g->map[i -1][j] == '0' || g->map[i -1][j] == 'C' || v_e(g))
				{
					g->map[i - 1][j] = 'P';
					mlx_put_image_to_window(g->mlx, g->mlx_window,
						g->img_pigeon, j * 48, (i - 1) * 48);
					mlx_put_image_to_window(g->mlx, g->mlx_window,
						g->img_ground, j * 48, i * 48);
					g->map[i][j] = '0';
					return (1);
				}
			}
		}
	}
	return (0);
}

int	move_down(t_game *g)
{
	int		i;
	int		j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P')
			{
				if (g->map[i +1][j] == '0' || g->map[i +1][j] == 'C' || v_e(g))
				{
					g->map[i + 1][j] = 'P';
					mlx_put_image_to_window(g->mlx, g->mlx_window,
						g->img_pigeon, j * 48, (i + 1) * 48);
					mlx_put_image_to_window(g->mlx, g->mlx_window,
						g->img_ground, j * 48, i * 48);
					g->map[i][j] = '0';
					return (1);
				}
			}
		}
	}
	return (0);
}
