#include "../cub3d.h"

void				is_dir_up(int left, t_ray ray)
{
	if (left)
	{
		if (((int)ray.hit_point.y % g_tile_size) == 0)
			g_dir.check_no = 1;
		else
			g_dir.check_we = 1;
	}
	else
	{
		if (((int)ray.hit_point.x % g_tile_size) == 0)
			g_dir.check_ea = 1;
		else
			g_dir.check_no = 1;
	}
}

void				is_dir_down(int left, t_ray ray)
{
	if (left)
	{
		if (((int)ray.hit_point.y % g_tile_size) == 0)
			g_dir.check_so = 1;
		else
			g_dir.check_we = 1;
	}
	else
	{
		if (((int)ray.hit_point.x % g_tile_size) == 0)
			g_dir.check_ea = 1;
		else
			g_dir.check_so = 1;
	}
}

double				get_texture_x(t_ray ray)
{
	double			texture_x;

	texture_x = 0;
	if (g_dir.check_no == 1 || g_dir.check_so == 1)
	{
		if (g_dir.check_no)
			texture_x = ((int)ray.hit_point.x % g_tile_size) * (g_dir.no_w / g_tile_size);
		else if (g_dir.check_so)
			texture_x = ((int)ray.hit_point.x % g_tile_size) * (g_dir.so_w / g_tile_size);
	}
	else if (g_dir.check_ea == 1 || g_dir.check_we == 1)
	{
		if (g_dir.check_ea)
			texture_x = ((int)ray.hit_point.y % g_tile_size) * (g_dir.ea_w / g_tile_size);
		else if (g_dir.check_we)
			texture_x = ((int)ray.hit_point.y % g_tile_size) * (g_dir.we_w / g_tile_size);
	}
	return (texture_x);
}

double				get_texture_y(double current_y, double start_y, double wall_height)
{
	double			texture_y;

	texture_y = 0;
	if (g_dir.check_no == 1 || g_dir.check_so == 1)
	{
		if (g_dir.check_no)
			texture_y = (current_y - start_y) * (g_dir.no_h / wall_height);
		else if (g_dir.check_so)
			texture_y = (current_y - start_y) * (g_dir.so_h / wall_height);
	}
	else if (g_dir.check_ea == 1 || g_dir.check_we == 1)
	{
		if (g_dir.check_ea)
			texture_y = (current_y - start_y) * (g_dir.ea_h / wall_height);
		else if (g_dir.check_we)
			texture_y = (current_y - start_y) * (g_dir.we_h / wall_height);
	}
	return (texture_y);
}