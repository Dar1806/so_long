/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:21:02 by nmeunier          #+#    #+#             */
/*   Updated: 2025/12/19 16:22:44 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_tab(int fd)
{
	char	**tab_map;
	char	*buffer;
	int		colonne;
	int		ligne;

	tab_map = 0;
	buffer = 0;
	ligne = 0;
	colonne = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		tab_map[ligne] = buffer;
		ligne++;
	}
	return (tab_map);
}

int	main(void)
{
	int		fd;
	int		i;
	char	**map;

	fd = open("maps.ber", O_RDONLY);
	map = create_tab(fd);
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
