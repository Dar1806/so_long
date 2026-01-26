/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:03:22 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/26 22:31:27 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game || ac != 2)
	{
		ft_putstr_fd("Error\nNeed a map", 1);
		free(game);
		return (0);
	}
	if (load_verif_map(game, av[1]))
		mlx_create(game);
	else
		free(game);
	return (0);
}
