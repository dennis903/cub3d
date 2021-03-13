/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:49:17 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 11:15:10 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				texture_setting()
{
	if (!(g_dir.north = mlx_xpm_file_to_image(g_game.mlx, g_md.north, &g_dir.no_w, &g_dir.no_h)))
		return (ERROR);
	if (!(g_dir.south = mlx_xpm_file_to_image(g_game.mlx, g_md.south, &g_dir.so_w, &g_dir.so_h)))
		return (ERROR);
	if (!(g_dir.east = mlx_xpm_file_to_image(g_game.mlx, g_md.east, &g_dir.ea_w, &g_dir.ea_h)))
		return (ERROR);
	if (!(g_dir.west = mlx_xpm_file_to_image(g_game.mlx, g_md.west, &g_dir.we_w, &g_dir.we_h)))
		return (ERROR);
	if (!(g_dir.sprite = mlx_xpm_file_to_image(g_game.mlx, g_md.sprite, &g_dir.sp_w, &g_dir.sp_h)))
		return (ERROR);
	if (!(g_dir.no_data = (int *)mlx_get_data_addr(g_dir.north, &g_dir.no_bpp, &g_dir.no_size_l, &g_dir.no_endian)))
		return (ERROR);
	if (!(g_dir.so_data = (int *)mlx_get_data_addr(g_dir.south, &g_dir.so_bpp, &g_dir.so_size_l, &g_dir.so_endian)))
		return (ERROR);
	if (!(g_dir.ea_data = (int *)mlx_get_data_addr(g_dir.east, &g_dir.ea_bpp, &g_dir.ea_size_l, &g_dir.ea_endian)))
		return (ERROR);
	if (!(g_dir.we_data = (int *)mlx_get_data_addr(g_dir.west, &g_dir.we_bpp, &g_dir.we_size_l, &g_dir.we_endian)))
		return (ERROR);
	if (!(g_dir.sp_data = (int *)mlx_get_data_addr(g_dir.sprite, &g_dir.sp_bpp, &g_dir.sp_size_l, &g_dir.sp_endian)))
		return (ERROR);
	return (0);
}

void			player_setting()
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

int				sprite_setting()
{
	g_sprite_num = count_sprite();
	if (g_sprite_num == 0)
		return (0);
	if (!(g_sprites = (t_sprite *)malloc(sizeof(t_sprite) * g_sprite_num)))
		return (ERROR);
	sprite_pos_set();
	return (0);
}

void			ray_setting()
{
	g_fov_angle = get_degree(60);
	g_num_rays = g_md.width;
	g_dist_from_player = ((g_md.width / 2) / (tan(g_fov_angle / 2)));
	if (!(g_rays = (t_ray *)malloc(sizeof(t_ray) * g_num_rays)))
		exit(1);
	if (g_num_rays == 0)
		exit(1);
}

int				cub_setting()
{
	if (!(g_game.win = mlx_new_window(g_game.mlx, g_md.width, g_md.height, "cub3d")))
		return (ERROR);
	if (!(g_game.img_2d.img = mlx_new_image(g_game.mlx, g_tile_size * g_idx_width, g_tile_size * g_idx_height)))
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