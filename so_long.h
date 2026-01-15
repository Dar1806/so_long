/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:27:58 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/15 14:06:13 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdalign.h>
# include "gnl/get_next_line.h"
# include "Libft/libft.h"

char	**copy_in_tab(char **dst, const char *src, int ligne);
char	**create_tab(char *map_path);
int		valid_map_border(char **tab_map);


#endif