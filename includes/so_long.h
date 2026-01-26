/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:27:58 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/26 19:15:01 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdalign.h>
# include <string.h>
# include "get_next_line.h"
# include "libft.h"
# include "../mlx/mlx.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*mlx_window;
	void	*img_wall;
	void	*img_ground;
	void	*img_pigeon_left;
	void	*img_pigeon_right;
	void	*img_collectible;
	void	*img_exit;
	int		move_count;
}	t_game;

char	**copy_in_tab(char **dst, const char *src, int ligne);
void	get_map_size(t_game *g, int *i, int *j);
void	free_all(t_game *game);
int		key_handler(int keycode, t_game *g);
int		valid_map_letters(char **tab_map);
int		valid_map_border(char **tab_map);
int		valid_map_stuck(char **tab_map);
int		valid_map_size(char **tab_map);
int		valid_map_pec(char **tab_map);
int		valid_map_check_c(char **tab);
char	**create_tab(char *map_path);
int		map_valid(char **tab_map);
void	create_ground(t_game *g);
void	create_wall(t_game *g);
void	mlx_create(t_game *g);
int		move_right(t_game *g);
int		destroy_w(t_game *g);
int		move_down(t_game *g);
int		move_left(t_game *g);
void	create_p(t_game *g);
void	create_c(t_game *g);
void	create_e(t_game *g);
int		move_up(t_game *g);
int		v_e(t_game *g);
void	free_tab(char **tab);

#endif