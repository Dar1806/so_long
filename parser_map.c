/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:21:02 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/05 16:46:47 by nmeunier         ###   ########.fr       */
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
			else if (tab_map[i][j] == 'C')
				valid_c++;
			else if (tab_map[i][j] == 'E')
				valid_e++;
		}																																	
	}
	return (valid_p == 1 && valid_e == 1 && valid_c >= 1);
}

int	main(void)
{
	int		i;
	int		valid_border;
	int		valid_pec;
	char	**map;

	valid_border = 0;
	map = create_tab("maps.ber");
	valid_border = valid_map_border(map);
	valid_pec = valid_map_pec(map);
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("valid_border : %d\n", valid_border);
	printf("valid_pec : %d\n", valid_pec  );
}
