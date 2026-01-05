/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:21:02 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/05 14:17:41 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *map_path)
{
	int		count;
	char	*buffer;
	int		fd;

	fd = open(map_path, O_RDONLY);
	count = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		count++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**create_tab(char *map_path)
{
	char	**tab_map;
	char	*buffer;
	int		ligne;
	int		fd;

	tab_map = malloc(sizeof(char *) * (count_lines(map_path) + 1));
	fd = open(map_path, O_RDONLY);
	if (!tab_map)
		return (0);
	ligne = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		tab_map[ligne++] = ft_strdup(buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	tab_map[ligne] = NULL;
	return (tab_map);
}

int	valid_map_border(char **tab_map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab_map[i][j])
	{
		while (tab_map[i][j] == '1')
		{
			if (tab_map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(void)
{
	int		fd;
	int		i;
	int		valid;
	char	**map;

	valid = 0;
	map = create_tab("maps.ber");
	valid = valid_map_border(map);
	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("%d\n", valid);
}
