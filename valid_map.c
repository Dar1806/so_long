/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:02:30 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/19 17:07:36 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map_border(char **tab_map)
{
	int	i;
	int	j;
	int	last_line;
	int	last_column;

	i = 0;
	while (tab_map[i])
		i++;
	last_line = i - 1;
	j = 0;
	while (tab_map[last_line][j])
		j++;
	last_column = j - 1;
	i = -1;
	while (tab_map[++i])
	{
		j = -1;
		while (tab_map[i][++j])
			if (((tab_map[i][j] != '1' && i == 0)
				|| ((tab_map[i][j] != '1') && i == last_line)
				|| ((tab_map[i][0] != '1')
				|| (tab_map[i][last_column] != '1'))))
				return (0);
	}
	return (1);
}

int	valid_map_pec(char **tab_map)
{
	int		i;
	int		j;
	int		valid_p;
	int		valid_e;
	int		valid_c;

	valid_p = 0;
	valid_e = 0;
	valid_c = 0;
	i = -1;
	while (tab_map[++i])
	{
		j = -1;
		while (tab_map[i][++j])
		{
			if (tab_map[i][j] == 'P')
				valid_p++;
			else if (tab_map[i][j] == 'E')
				valid_e++;
			else if (tab_map[i][j] == 'C')
				valid_c++;
		}
	}
	return (valid_p == 1 && valid_e == 1 && valid_c >= 1);
}

int	valid_map_size(char **tab_map)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 0;
	while (tab_map[i][max])
		max++;
	i = -1;
	while (tab_map[++i])
	{
		j = 0;
		while (tab_map[i][j])
			j++;
		if (j != max)
			return (0);
	}
	return (1);
}

int	valid_map_letters(char **tab_map)
{
	int	i;
	int	j;

	i = 0;
	while (tab_map[i])
	{
		j = 0;
		while (tab_map[i][j])
		{
			if ((tab_map[i][j] != '1')
			&& (tab_map[i][j] != '0')
			&& (tab_map[i][j] != 'P')
			&& (tab_map[i][j] != 'E')
			&& (tab_map[i][j] != 'C'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	map_valid(char **tab_map)
{
	if (!valid_map_border(tab_map))
		ft_putstr_fd("Error\nThe map is not surrounded by walls (1)\n", 1);
	else if (!valid_map_pec(tab_map))
		ft_putstr_fd("Error\nThe map does not contains the valid PEC\n", 1);
	else if (!valid_map_size(tab_map))
		ft_putstr_fd("Error\nThe size of the map is not valid\n", 1);
	else if (!valid_map_letters(tab_map))
		ft_putstr_fd("Error\nTheres not only 01PEC characters\n", 1);
	else if (!valid_map_stuck(tab_map))
		ft_putstr_fd("Error\nThe player cannot take all of the C\n", 1);
	else
		ft_putstr_fd("The map is valid\n", 1);
}
