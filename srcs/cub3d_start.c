/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:49:08 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 15:22:00 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				main_loop(void)
{
	update();
	render();
	mlx_put_image_to_window(g_game.mlx, g_game.win,
	g_game.img_3d.img, 0, 0);
	if (g_keys.tab_key == 1)
		mlx_put_image_to_window(g_game.mlx, g_game.win,
		g_game.img_2d.img, 0, 0);
	return (0);
}
