/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:55 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 17:53:35 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				image_reset_2d(void)
{
	int				i;
	int				j;

	i = 0;
	while (i < g_tile_size * g_idx_height)
	{
		j = 0;
		while (j < g_tile_size * g_idx_width)
		{
			g_game.img_2d.data[i * g_tile_size * g_idx_width + j] = 0x000000;
			j++;
		}
		i++;
	}
}

void				image_reset_3d(void)
{
	int				i;
	int				j;

	i = 0;
	while (i < g_md.height)
	{
		j = 0;
		while (j < g_md.width)
		{
			g_game.img_3d.data[i * g_md.width + j] = 0x000000;
			j++;
		}
		i++;
	}
}
