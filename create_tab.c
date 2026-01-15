/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:06:42 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/15 14:06:49 by nmeunier         ###   ########.fr       */
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
		if (buffer[ft_strlen(buffer) - 1] == '\n')
			buffer[ft_strlen(buffer) - 1] = '\0';
		tab_map[ligne] = ft_strdup(buffer);
		free(buffer);
		buffer = get_next_line(fd);
		ligne++;
	}
	tab_map[ligne] = NULL;
	return (tab_map);
}
