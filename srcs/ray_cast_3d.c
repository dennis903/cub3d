#include "../cub3d.h"

void					draw_ceiling()
{
	int					i;
	int					j;

	i = 0;
	while (i < g_map_height / 2)
	{
		j = 0;
		while (j < g_map_width)
		{
			game.img.data[i * g_map_width + j] = fill_color(md.f);
			j++;
		}
		i++;
	}
}

void					draw_floor()
{
	int					i;
	int					j;

	i = g_map_height / 2;
	while (i < g_map_height)
	{
		j = 0;
		while (j < g_map_width)
		{
			game.img.data[i * g_map_width + j] = fill_color(md.c);
			j++;
		}
		i++;
	}
}

void					draw_3d_rectangle(double x1, double y1, double x2, double y2)
{
	int					i;
	int					j;

	i = 0;
	while(i < y2 + 0)
	{
		j = 0;
		while (j < x2)
		{
			game.img.data[calc_idx((int)(x1 + j), (int)(y1 + i))] = 0xF1F1F1;
			j++;
		}
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
		g_3d.dist_from_player = (g_map_width / 2) * tan(g_fov_angle / 2);
		g_3d.proj_wall_height = (g_tile_size / correct_wall_dist) * g_3d.dist_from_player;
		draw_3d_rectangle(i , (g_map_height / 2) - (g_3d.proj_wall_height / 2),
		1, g_3d.proj_wall_height);
		i++;
	}
}