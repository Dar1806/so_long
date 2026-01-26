/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:36:26 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/26 23:01:20 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	track_exit(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'E')
			{
				g->exit_j = j;
				g->exit_i = i;
				return ;
			}
		}
	}
}

int	verif_exit(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P' && i == g->exit_i && j == g->exit_j)
			{
				if (valid_map_check_c(g->map))
				{
					ft_putstr_fd("You won!\n", 1);
					destroy_w(g);
					return (1);
				}
				return (0);
			}
		}
	}
	return (0);
}
