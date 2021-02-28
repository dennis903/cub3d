#include "../cub3d.h"

void					draw_ceiling()
{
	int					i;
	int					j;

	i = 0;
	while (i < md.height / 2)
	{
		j = 0;
		while (j < md.width)
		{
			game.img.data[i * md.width + j] = fill_color(md.f);
			j++;
		}
		i++;
	}
}

void					draw_floor()
{
	int					i;
	int					j;

	i = md.height / 2;
	while (i < md.height)
	{
		j = 0;
		while (j < md.width)
		{
			game.img.data[i * md.width + j] = fill_color(md.c);
			j++;
		}
		i++;
	}
}

void					draw_3d_wall(double x, double start_y, double wall_height, t_ray ray)
{
	t_point				texture;
	double				temp_wall_height;
	double				temp_start_y;
	int					color;
	int					i;

	temp_start_y = start_y;
	temp_wall_height = wall_height;
	color = 0;
	if (start_y < 0)
		start_y = 0;
	if (wall_height > md.height)
		wall_height = md.height;
	check_direction(ray);
	texture.x = get_texture_x(ray);
	i = start_y;
	while (i < wall_height)
	{
		texture.y = get_texture_y(i, temp_start_y, temp_wall_height);
		color = get_texture_color(texture.x, texture.y);
		game.img.data[i * md.width + (int)x] = color;
		i++;
	}
}

void					draw_wall()
{
	int					i;
	t_ray				ray;
	double				ray_dist;
	double				correct_wall_dist;

	i = 0;
	g_3d.actual_wall_height = g_tile_size;
	while (i < g_num_rays)
	{
		ray = g_rays[i];
		ray_dist = ray.distance;
		correct_wall_dist = cos(player.rot_angle - ray.ray_angle) * ray_dist;
		g_3d.dist_from_player = (md.width / 2) * tan(g_fov_angle / 2);
		g_3d.proj_wall_height = (g_tile_size / correct_wall_dist) * g_3d.dist_from_player;
		draw_3d_wall(i, ((md.height / 2) - (g_3d.proj_wall_height / 2)), g_3d.proj_wall_height, ray);
		i++;
	}
}