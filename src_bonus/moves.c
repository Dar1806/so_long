/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:39:33 by nmeunier          #+#    #+#             */
/*   Updated: 2026/02/03 17:52:13 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*moves_to_string(int moves)
{
	char	*str;
	char	*tmp;

	str = "Moves: ";
	tmp = ft_itoa(moves);
	str = ft_strjoin(str, tmp);
	free(tmp);
	return (str);
}

int	render_moves(t_game *g)
{
	int	x;

	if (g->moves_str)
		free(g->moves_str);
	g->moves_str = moves_to_string(g->move_count);
	x = 0;
	while (x < 96)
	{
		mlx_put_image_to_window(g->mlx, g->mlx_window, g->img_wall, x, 0);
		x += 48;
	}
	mlx_string_put(g->mlx, g->mlx_window, 20, 20,
		0xFFFFFF, g->moves_str);
	return (0);
}
