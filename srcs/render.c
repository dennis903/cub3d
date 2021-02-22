#include "../cub3d.h"

void				draw_2d_ray()
{
	int				col_id;
	int				i;
	double			ray_angle;

	col_id = 0;
	i = 0;
	ray_angle = player.rot_angle;// - (g_fov_angle / 2);
	while (i < g_num_rays)
	{
		g_rays[i].ray_angle = normalize_angle(ray_angle);
		ray_cast(col_id, ray_angle);
		// draw_line(player.x, player.y, g_rays[i].hit_point.x, g_rays[i].hit_point.y, 0xFF0000);
		// ray_angle = ray_angle + (g_fov_angle / g_num_rays);
		col_id++;
		i++;
	}
}

void				image_reset()
{
	int				i;
	int				j;

	i = 0;
	while (i < g_map_height)
	{
		j = 0;
		while (j < g_map_width)
		{
			game.img.data[i * g_map_width + j] = 0x000000;
			j++;
		}
		i++;
	}
}


void				raycast_2d()
{
	draw_rectangles();
	draw_lines();
	draw_player();
	draw_2d_ray();
}

void				render()
{
	image_reset();
	mlx_put_image_to_window(game.mlx, game.win, game.img.img, 0, 0);
	raycast_2d();
	mlx_put_image_to_window(game.mlx, game.win, game.img.img, 0, 0);
}