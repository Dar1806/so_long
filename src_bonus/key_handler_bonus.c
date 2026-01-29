/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:21:07 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/29 15:31:33 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_handler(int keycode, t_game *g)
{
	int	prev_move_count;

	prev_move_count = g->move_count;
	g->modulo++;
	if (keycode == KEY_W && move_up(g))
		g->move_count++;
	else if (keycode == KEY_A && move_left(g))
		g->move_count++;
	else if (keycode == KEY_S && move_down(g))
		g->move_count++;
	else if (keycode == KEY_D && move_right(g))
		g->move_count++;
	else if (keycode == KEY_ESC)
		destroy_w(g);
	verif_exit(g);
	if (g->modulo % 2 == 0 && g->move_count > prev_move_count)
		enemy_to_player(g);
	if (g->move_count > prev_move_count)
	{
		ft_putstr_fd("Moves : ", 1);
		ft_putnbr_fd(g->move_count, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
