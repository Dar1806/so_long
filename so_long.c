/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:53:40 by nmeunier          #+#    #+#             */
/*   Updated: 2025/12/19 18:53:35 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int		main()
{
	int	er;
fd;
	char	*buff
	fd = open("maps.ber", O_RDONLY);
	while ((buffer = get_next_line(fd)) != NULL)
	{
		printf("%s", buffer);
	}
}