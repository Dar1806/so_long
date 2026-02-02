/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:03:22 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/02 15:59:30 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = calloc(1, sizeof(t_game));
	if (!game || ac != 2)
	{
		ft_putstr_fd("Error\nNeed a map\n", 1);
		free(game);
		return (0);
	}
	if (!valid_name(av[1]))
	{
		ft_putstr_fd("Error\nMap name invalid\n", 1);
		free(game);
		return (0);
	}
	if (load_verif_map(game, av[1]))
		mlx_create(game);
	else
		free(game);
	return (0);
}

int	valid_name(char *map_path)
{
	int	i;
	int	len;

	len = 0;
	while (map_path[len])
		len++;
	if (len < 5)
		return (0);
	i = len - 4;
	if (map_path[i] == '.' && map_path[i + 1] == 'b'
		&& map_path[i + 2] == 'e' && map_path[i + 3] == 'r')
		return (1);
	return (0);
}
