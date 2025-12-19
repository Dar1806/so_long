/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:51:57 by nmeunier          #+#    #+#             */
/*   Updated: 2025/12/19 16:09:04 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_in_tab(char **dst, const char *src, int colonne)
{
	size_t	ligne;
	size_t	src_len;

	src_len = ft_strlen(src);
	ligne = 0;
	while (src[ligne] && ligne)
	{
		dst[ligne][colonne] = src[colonne];
		ligne++;
	}
	dst[ligne][colonne] = '\0';
	return (dst);
}
