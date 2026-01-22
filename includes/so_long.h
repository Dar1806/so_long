/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:27:58 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/22 17:28:01 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdalign.h>
# include "get_next_line.h"
# include "libft.h"
# include "../mlx/mlx.h"

typedef struct s_data {
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

char	**copy_in_tab(char **dst, const char *src, int ligne);
char	**create_tab(char *map_path);
int		valid_map_border(char **tab_map);
int		valid_map_pec(char **tab_map);
int		valid_map_size(char **tab_map);
int		valid_map_letters(char **tab_map);
int		valid_map_stuck(char **tab_map);
int		valid_map_check_c(char **tab);
int		map_valid(char **tab_map);
void	mlx_create(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);








#endif