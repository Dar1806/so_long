/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:40:44 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/29 16:22:57 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_size(t_game *g, int *i, int *j)
{
	*i = 0;
	while (g->map[*i])
		(*i)++;
	*j = ft_strlen(g->map[0]);
	*i *= 48;
	*j *= 48;
}

void	mlx_create(t_game *g)
{
	int		map_width;
	int		map_height;

	map_width = 0;
	map_height = 0;
	g->mlx = mlx_init();
	get_map_size(g, &map_width, &map_height);
	g->mlx_window = mlx_new_window(g->mlx, map_height, map_width, "Game");
	create_ground(g);
	create_wall(g);
	create_p(g);
	create_c(g);
	create_e(g);
	create_enemy(g);
	track_exit(g);
	g->move_count = 0;
	g->modulo = 0;
	g->width = 0;
	g->height = 0;
	mlx_key_hook(g->mlx_window, key_handler, g);
	mlx_hook(g->mlx_window, 17, 0, destroy_w, g);
	mlx_loop(g->mlx);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_tab(game->map);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_ground)
		mlx_destroy_image(game->mlx, game->img_ground);
	if (game->img_pigeon_left)
		mlx_destroy_image(game->mlx, game->img_pigeon_left);
	if (game->img_pigeon_right)
		mlx_destroy_image(game->mlx, game->img_pigeon_right);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_enemy_right)
		mlx_destroy_image(game->mlx, game->img_enemy_right);
	if (game->img_enemy_left)
		mlx_destroy_image(game->mlx, game->img_enemy_left);
	mlx_destroy_window(game->mlx, game->mlx_window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

int	destroy_w(t_game *g)
{
	free_all(g);
	exit(0);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
