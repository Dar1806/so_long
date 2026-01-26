/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:03:22 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/26 19:05:42 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	char	**tab_map;
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	if (ac != 2)
	{
		ft_putstr_fd("Error\nNeed a map", 1);
		free(game);
		return (0);
	}
	tab_map = create_tab(av[1]);
	if (!tab_map)
	{
		ft_putstr_fd("Error\nMap does not exist\n", 1);
		return (0);
	}
	if (map_valid(tab_map))
	{
		free_tab(tab_map);
		game->map = create_tab(av[1]);
		mlx_create(game);
	}
	return (0);
}
