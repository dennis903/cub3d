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
			game.img_3d.data[i * md.width + j] = fill_color(md.f);
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
			game.img_3d.data[i * md.width + j] = fill_color(md.c);
			j++;
		}
		i++;
	}
}

void					draw_3d_wall(double x, int wall_strip_height, t_ray ray)
{
	int					i;
	int					start_point;
	int					end_point;
	int					screen_y;
	t_point				get_texture;

	start_point = (md.height / 2) - (wall_strip_height / 2);
	if (start_point < 0)
		start_point = 0;
	end_point = (md.height / 2) + (wall_strip_height / 2);
	if (end_point >= md.height)
		end_point = md.height - 1;
	i = start_point;
	check_direction(ray);
	get_texture.x = get_texture_x(ray);
	while (i < end_point)
	{
		screen_y = i + (wall_strip_height / 2) - (md.height / 2);
		get_texture.y = get_texture_y(screen_y,  wall_strip_height);
		game.img_3d.data[i * md.width + (int)x] = get_texture_color(get_texture.x, get_texture.y);
		i++;
	}
}

void					draw_wall()
{
	int					i;
	double				dist_from_player;
	double				proj_wall_height;
	double				correct_ray_dist;
	int					wall_strip_height;

	i = 0;
	while (i < g_num_rays)
	{
		correct_ray_dist = cos(player.rot_angle - g_rays[i].ray_angle) * (g_rays[i].distance);
		dist_from_player = (md.width / 2) * (tan(g_fov_angle / 2));
		proj_wall_height = (g_tile_size * 2.5 / correct_ray_dist) * dist_from_player;
		wall_strip_height = (int)proj_wall_height;
		draw_3d_wall(i, wall_strip_height, g_rays[i]);
		i++;
	}
}