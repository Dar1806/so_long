/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:27:58 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/30 12:31:03 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdalign.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
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
	int		width;
	int		height;
	int		exit_j;
	int		exit_i;
	void	*img_enemy_right;
	void	*img_enemy_left;
	int		enemy_j;
	int		enemy_i;
	int		enemy_direction;
	int		player_i;
	int		player_j;
	int		modulo;
}	t_game;

char	**copy_in_tab(char **dst, const char *src, int ligne);
int		load_verif_map(t_game *game, char *map_path);
void	get_map_size(t_game *g, int *i, int *j);
char	**validate_and_return(char **tab_map);
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
void	free_all(t_game *game);
void	mlx_create(t_game *g);
void	track_exit(t_game *g);
int		verif_exit(t_game *g);
int		move_right(t_game *g);
int		destroy_w(t_game *g);
int		move_down(t_game *g);
void	free_tab(char **tab);
int		move_left(t_game *g);
void	create_p(t_game *g);
void	create_c(t_game *g);
void	create_e(t_game *g);
int		move_up(t_game *g);

int		check_enemy_collision(t_game *g);
void	move_enemy_right(t_game *g);
void	enemy_to_player(t_game *g);
void	move_enemy_left(t_game *g);
int		destroy_w_bonus(t_game *g);
void	move_enemy_down(t_game *g);
void	locate_enemy_p(t_game *g);
void	move_enemy_up(t_game *g);
void	render_enemy(t_game *g);
void	create_enemy(t_game *g);
void	first_enemy(t_game *g);
void	move_enemy(t_game *g);
int		game_loop(t_game *g);

#endif