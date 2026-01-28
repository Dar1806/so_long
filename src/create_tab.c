/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:06:42 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/28 22:47:56 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>

char	**validate_and_return(char **tab_map)
{
	if (!tab_map[0])
	{
		free(tab_map);
		return (NULL);
	}
	return (tab_map);
}

int	count_lines(char *map_path)
{
	int		count;
	char	*buffer;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
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

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tab_map = malloc(sizeof(char *) * (count_lines(map_path) + 1));
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
	return (validate_and_return(tab_map));
}
