/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:40:44 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/24 19:57:10 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_size(char **tab_map, int *i, int *j)
{
	*i = 0;
	while (tab_map[*i])
		(*i)++;
	*j = ft_strlen(tab_map[0]);
	*i *= 48;
	*j *= 48;
}

void	mlx_create(char **tab_map)
{
	void	*mlx;
	void	*mlx_window;
	int		map_width;
	int		map_height;

	mlx = mlx_init();
	get_map_size(tab_map, &map_width, &map_height);
	mlx_window = mlx_new_window(mlx, map_height, map_width, "Game");
	create_ground(mlx, mlx_window, tab_map);
	create_wall(mlx, mlx_window, tab_map);
	create_p(mlx, mlx_window, tab_map);
	create_c(mlx, mlx_window, tab_map);
	create_e(mlx, mlx_window, tab_map);
	mlx_loop(mlx);
}
