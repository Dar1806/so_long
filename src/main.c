/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:03:22 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/24 18:18:27 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	char	**tab_map;
	int		i;

	if (ac == 2)
	{
		tab_map = create_tab(av[1]);
		if (!tab_map)
		{
			ft_putstr_fd("Error\nMap does not exist\n", 1);
			return (0);
		}
		if (map_valid(tab_map))
		{
			i = 0;
			while (tab_map[i])
			{
				printf("%s\n", tab_map[i]);
				i++;
			}
			tab_map = create_tab(av[1]);
			mlx_create(tab_map);
		}
	}
	return (0);
}
