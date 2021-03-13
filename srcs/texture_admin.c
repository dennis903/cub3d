/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_admin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:13 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 15:27:46 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void						init_direction()
{
	g_dir.check_no = 0;
	g_dir.check_so = 0;
	g_dir.check_we = 0;
	g_dir.check_ea = 0;
}

unsigned int				fill_color(t_color *color)
{
	int						r;
	int						g;
	int						b;

	r = color->red;
	g = color->green;
	b = color->blue;
	return (((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF));
}

void						check_direction(t_ray ray)
{
	int						angle_side_down;
	int						angle_side_left;
	double					angle;

	angle_side_down = 0;
	angle_side_left = 0;
	angle = ray.ray_angle;
	if (angle > 0 && angle < PI)
		angle_side_down = 1;
	if (angle > 0.5 * PI && angle < 1.5 * PI)
		angle_side_left = 1;
	init_direction();
	if (!angle_side_down)
		is_dir_up(angle_side_left, ray);
	else
		is_dir_down(angle_side_left, ray);
}

void						put_xpm_file_to_image(void)
{
	if (!(g_dir.north = mlx_xpm_file_to_image(g_game.mlx, g_md.north,
	&g_dir.no_w, &g_dir.no_h)))
		return (ERROR);
	if (!(g_dir.south = mlx_xpm_file_to_image(g_game.mlx, g_md.south,
	&g_dir.so_w, &g_dir.so_h)))
		return (ERROR);
	if (!(g_dir.east = mlx_xpm_file_to_image(g_game.mlx, g_md.east,
	&g_dir.ea_w, &g_dir.ea_h)))
		return (ERROR);
	if (!(g_dir.west = mlx_xpm_file_to_image(g_game.mlx, g_md.west,
	&g_dir.we_w, &g_dir.we_h)))
		return (ERROR);
	if (!(g_dir.sprite = mlx_xpm_file_to_image(g_game.mlx, g_md.sprite,
	&g_dir.sp_w, &g_dir.sp_h)))
		return (ERROR);

}

void						put_get_data_addr(void)
{
	if (!(g_dir.no_data = (int *)mlx_get_data_addr(g_dir.north, &g_dir.no_bpp,
	&g_dir.no_size_l, &g_dir.no_endian)))
		return (ERROR);
	if (!(g_dir.so_data = (int *)mlx_get_data_addr(g_dir.south, &g_dir.so_bpp,
	&g_dir.so_size_l, &g_dir.so_endian)))
		return (ERROR);
	if (!(g_dir.ea_data = (int *)mlx_get_data_addr(g_dir.east, &g_dir.ea_bpp,
	&g_dir.ea_size_l, &g_dir.ea_endian)))
		return (ERROR);
	if (!(g_dir.we_data = (int *)mlx_get_data_addr(g_dir.west, &g_dir.we_bpp,
	&g_dir.we_size_l, &g_dir.we_endian)))
		return (ERROR);
	if (!(g_dir.sp_data = (int *)mlx_get_data_addr(g_dir.sprite, &g_dir.sp_bpp,
	&g_dir.sp_size_l, &g_dir.sp_endian)))
		return (ERROR);
}