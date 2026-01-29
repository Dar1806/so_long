/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 02:12:52 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/29 16:19:23 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_to_player(t_game *g)
{
	locate_enemy_p(g);
	if ((abs(g->enemy_j - g->player_j)) > (abs(g->enemy_i - g->player_i)))
	{
		if (g->enemy_j < g->player_j)
			move_enemy_right(g);
		else if (g->enemy_j > g->player_j)
			move_enemy_left(g);
	}
	else
	{
		if (g->enemy_i < g->player_i)
			move_enemy_down(g);
		else if (g->enemy_i > g->player_i)
			move_enemy_up(g);
	}
}

void	move_enemy_up(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'N' && (g->map[i - 1][j] == '0'
				|| (g->map[i - 1][j] == 'P')))
			{
				if (g->map[i - 1][j] == 'P')
					destroy_w_bonus(g);
				g->map[i - 1][j] = 'N';
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_enemy_right, j * 48, (i - 1) * 48);
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_ground, j * 48, i * 48);
				g->map[i][j] = '0';
				return ;
			}
		}
	}
}

void	move_enemy_down(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'N' && ((g->map[i + 1][j] == '0'
				|| (g->map[i + 1][j] == 'P'))))
			{
				if (g->map[i + 1][j] == 'P')
					destroy_w_bonus(g);
				g->map[i + 1][j] = 'N';
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_enemy_right, j * 48, (i + 1) * 48);
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_ground, j * 48, i * 48);
				g->map[i][j] = '0';
				return ;
			}
		}
	}
}

void	move_enemy_right(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'N' && ((g->map[i][j + 1] == '0')
				|| (g->map[i][j + 1] == 'P')))
			{
				if (g->map[i][j + 1] == 'P')
					destroy_w_bonus(g);
				g->map[i][j + 1] = 'N';
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_enemy_right, (j + 1) * 48, i * 48);
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_ground, j * 48, i * 48);
				g->map[i][j] = '0';
				return ;
			}
		}
	}
}

void	move_enemy_left(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'N' && (g->map[i][j - 1] == '0'
				|| g->map[i][j - 1] == 'P'))
			{
				if (g->map[i][j - 1] == 'P')
					destroy_w_bonus(g);
				g->map[i][j - 1] = 'N';
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_enemy_left, (j - 1) * 48, i * 48);
				mlx_put_image_to_window(g->mlx, g->mlx_window,
					g->img_ground, j * 48, i * 48);
				g->map[i][j] = '0';
				return ;
			}
		}
	}
}
