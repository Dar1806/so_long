/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:21:07 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/26 16:42:04 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_handler(int keycode, t_game *g)
{
	if (keycode == KEY_W)
	{
		if (move_up(g))
			g->move_count++;
	}
	if (keycode == KEY_A)
	{
		if (move_left(g))
			g->move_count++;
	}
	else if (keycode == KEY_S)
	{
		if (move_down(g))
			g->move_count++;
	}
	else if (keycode == KEY_D)
	{
		if (move_right(g))
			g->move_count++;
	}
	else if (keycode == KEY_ESC)
		destroy_w();
	ft_putnbr_fd(g->move_count, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	destroy_w(void)
{
	exit(0);
	return (0);
}

int	v_e(t_game *g)
{
	if (valid_map_check_c(g->map))
	{		
		ft_putstr_fd("You won!\n", 1);
		destroy_w();
		return (1);
	}
	ft_putstr_fd("Collect all items before exiting!\n", 1);
	return (0);
}
