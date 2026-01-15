/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:21:02 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/15 15:30:59 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map_size(char **tab_map)
{
	int	i;
	int	j;
	int	max;

	max = 0;
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
	i = -1;
	return (1);
}

int	valid_map_letters(char **tab_map)
{
	int	i;
	int	j;

	i = -1;
	while (tab_map[i++])
	{
		j = -1;
		while (tab_map[i][j++])
			if (tab_map[i][j] != '1'
			|| tab_map[i][j] != '0'
			|| tab_map[i][j] != 'P'
			|| tab_map[i][j] != 'E'
			|| tab_map[i][j] != 'C')
				return (0);
	}
	return (1);
}

void	map_valid(char **tab_map)
{
	if (!valid_map_border(tab_map))
		ft_putstr_fd("border not valid\n", 1);
	if (!valid_map_pec(tab_map))
		ft_putstr_fd("pec not valid\n", 1);
	if (!valid_map_size(tab_map))
		ft_putstr_fd("size not valid\n", 1);
	
}

int	main(void)
{
	char	**tab_map;
	int		i;

	tab_map = create_tab("maps.ber");
	i = 0;
	while (tab_map[i])
	{
		printf("%s\n", tab_map[i]);
		i++;
	}
	map_valid(tab_map);
}
