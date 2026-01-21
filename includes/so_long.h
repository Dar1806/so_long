/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:27:58 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/21 15:02:13 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdalign.h>
# include "get_next_line.h"
# include "libft.h"

char	**copy_in_tab(char **dst, const char *src, int ligne);
char	**create_tab(char *map_path);
int		valid_map_border(char **tab_map);
int		valid_map_pec(char **tab_map);
int		valid_map_size(char **tab_map);
int		valid_map_letters(char **tab_map);
int		valid_map_stuck(char **tab_map);
int		valid_map_check_c(char **tab);
void	map_valid(char **tab_map);







#endif