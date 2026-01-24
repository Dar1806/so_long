/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:27:58 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/24 19:53:19 by nmeunier         ###   ########.fr       */
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

void	create_ground(void *mlx, void *mlx_window, char **tab_map);
void	create_wall(void *mlx, void *mlx_window, char **tab_map);
void	create_p(void *mlx, void *mlx_window, char **tab_map);
void	create_c(void *mlx, void *mlx_window, char **tab_map);
void	create_e(void *mlx, void *mlx_window, char **tab_map);
char	**copy_in_tab(char **dst, const char *src, int ligne);
void	get_map_size(char **tab_map, int *i, int *j);
int		valid_map_letters(char **tab_map);
int		valid_map_border(char **tab_map);
int		valid_map_stuck(char **tab_map);
int		valid_map_size(char **tab_map);
int		valid_map_pec(char **tab_map);
int		valid_map_check_c(char **tab);
char	**create_tab(char *map_path);
void	mlx_create(char **tab_map);
int		map_valid(char **tab_map);

#endif