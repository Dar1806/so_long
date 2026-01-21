/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:03:22 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/21 15:32:12 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

int	main(int ac, char **av)
{
	char	**tab_map;
/* 	void	*mlx;
	void	*mlx_window; */

	if (ac == 2)
	{

		tab_map = create_tab(av[1]);
		if (!tab_map)
		{
			ft_putstr_fd("Map does not exist\n", 1);
			return (0);
		}
/* 		mlx = mlx_init();
		mlx_window = mlx_new_window(mlx, 500, 500, "test");
		mlx_loop(mlx); */
	}
	return (0);
}
