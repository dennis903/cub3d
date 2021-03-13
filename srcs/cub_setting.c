/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:49:17 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 15:29:20 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				texture_setting(void)
{
	put_xpm_file_to_image();
	put_get_data_addr();
	return (0);
}

void			player_setting(void)
{
	int			i;
	int			j;

	i = 0;
	while (i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (g_game.map[i][j] == 'N' || g_game.map[i][j] == 'S'
			|| g_game.map[i][j] == 'W' || g_game.map[i][j] == 'E')
			{
				set_angle(g_game.map[i][j]);
				player_init(i, j);
			}
			j++;
		}
		i++;
	}
}

int				sprite_setting(void)
{
	g_sprite_num = count_sprite();
	if (g_sprite_num == 0)
		return (0);
	if (!(g_sprites = (t_sprite *)malloc(sizeof(t_sprite) * g_sprite_num)))
		return (ERROR);
	sprite_pos_set();
	return (0);
}

void			ray_setting(void)
{
	g_fov_angle = get_degree(60);
	g_num_rays = g_md.width;
	g_dist_from_player = ((g_md.width / 2) / (tan(g_fov_angle / 2)));
	if (!(g_rays = (t_ray *)malloc(sizeof(t_ray) * g_num_rays)))
		exit(1);
	if (g_num_rays == 0)
		exit(1);
}

int				cub_setting(void)
{
	if (!(g_game.win = mlx_new_window(g_game.mlx, g_md.width, g_md.height, "cub3d")))
		return (ERROR);
	if (!(g_game.img_2d.img = mlx_new_image(g_game.mlx, g_tile_size * g_idx_width,
	g_tile_size * g_idx_height)))
		return (ERROR);
	if (!(g_game.img_3d.img = mlx_new_image(g_game.mlx, g_md.width, g_md.height)))
		return (ERROR);
	if (!(g_game.img_2d.data = (int *)mlx_get_data_addr(g_game.img_2d.img, &(g_game.img_2d.bpp),
	&(g_game.img_2d.size_l), &(g_game.img_2d.endian))))
		return (ERROR);
	if (!(g_game.img_3d.data = (int *)mlx_get_data_addr(g_game.img_3d.img, &(g_game.img_3d.bpp),
	&(g_game.img_3d.size_l), &(g_game.img_3d.endian))))
		return (ERROR);
	if (texture_setting() == ERROR)
		return (ERROR);
	if (sprite_setting() == ERROR)
		return (ERROR);
	player_setting();
	ray_setting();
	mlx_hook(g_game.win, X_EVENT_KEY_PRESS, 0, key_press, 0);
	mlx_hook(g_game.win, X_EVENT_KEY_release, 0, key_release, 0);
	mlx_hook(g_game.win, X_EVENT_KEY_EXIT, 0, key_exit, 0);
	return (0);
}
