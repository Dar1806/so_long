/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:40:44 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/26 19:14:27 by nmeunier         ###   ########.fr       */
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

	g->mlx = mlx_init();
	get_map_size(g, &map_width, &map_height);
	g->mlx_window = mlx_new_window(g->mlx, map_height, map_width, "Game");
	create_ground(g);
	create_wall(g);
	create_p(g);
	create_c(g);
	create_e(g);
	v_e(g);
	mlx_key_hook(g->mlx_window, key_handler, g);
	mlx_hook(g->mlx_window, 17, 0, destroy_w, g);
	mlx_loop(g->mlx);
}

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_ground);
	mlx_destroy_image(game->mlx, game->img_pigeon_left);
	mlx_destroy_image(game->mlx, game->img_pigeon_right);
	mlx_destroy_image(game->mlx, game->img_collectible);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_window(game->mlx, game->mlx_window);
	mlx_destroy_display(game->mlx);
	free(game);
}

int	destroy_w(t_game *g)
{
	free_all(g);
	exit(0);
	return (0);
}

int	v_e(t_game *g)
{
	if (valid_map_check_c(g->map))
	{		
		ft_putstr_fd("You won!\n", 1);
		destroy_w(g);
		return (1);
	}
	return (0);
}
