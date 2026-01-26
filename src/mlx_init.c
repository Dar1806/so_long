/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:40:44 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/26 16:40:52 by nmeunier         ###   ########.fr       */
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
	mlx_hook(g->mlx_window, 17, 0, destroy_w, NULL);
	mlx_loop(g->mlx);
}
