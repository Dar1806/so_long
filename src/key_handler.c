/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:21:07 by nmeunier          #+#    #+#             */
/*   Updated: 2026/01/26 18:45:16 by nmeunier         ###   ########.fr       */
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
		destroy_w(g);
	ft_putnbr_fd(g->move_count, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
