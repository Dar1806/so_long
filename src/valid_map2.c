/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:21:02 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/30 12:50:39 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	replace_p(char *n, char *s, char *w, char *e)
{
	int	change;

	change = 0;
	if (*n == '0' || *n == 'C')
	{
		*n = 'P';
		change++;
	}
	if (*s == '0' || *s == 'C')
	{
		*s = 'P';
		change++;
	}
	if (*w == '0' || *w == 'C')
	{
		*w = 'P';
		change++;
	}
	if (*e == '0' || *e == 'C')
	{
		*e = 'P';
		change++;
	}
	return (change);
}

int	valid_map_stuck(char **tab_map)
{
	int	i;
	int	j;
	int	change;

	change = 1;
	while (change != 0)
	{
		i = -1;
		change = 0;
		while (tab_map[++i])
		{
			j = -1;
			while (tab_map[i][++j])
			{
				if (tab_map[i][j] == 'P')
				{
					change += replace_p(&tab_map[i - 1][j], &tab_map[i + 1][j],
							&tab_map[i][j - 1], &tab_map[i][j + 1]);
				}
			}
		}
	}
	return (valid_map_check_c(tab_map));
}

int	valid_map_check_c(char **tab_map)
{
	int	i;
	int	j;

	i = -1;
	while (tab_map[++i])
	{
		j = -1;
		while (tab_map[i][++j])
		{
			if (tab_map[i][j] == 'C')
				return (0);
			if (tab_map[i][j] == 'E')
			{
				if (tab_map[i - 1][j] != 'P'
					&& tab_map[i + 1][j] != 'P'
					&& tab_map[i][j - 1] != 'P'
					&& tab_map[i][j + 1] != 'P')
					return (0);
			}
		}
	}
	return (1);
}

int	load_verif_map(t_game *game, char *map_path)
{
	char	**tab_map;

	tab_map = create_tab(map_path);
	if (!tab_map)
	{
		ft_putstr_fd("Error\nMap does not exist\n", 1);
		return (0);
	}
	if (!map_valid(tab_map))
	{
		free_tab(tab_map);
		return (0);
	}
	free_tab(tab_map);
	game->map = create_tab(map_path);
	return (1);
}
