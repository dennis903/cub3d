#include "../cub3d.h"

void				draw_2d_ray()
{
	int				col_id;
	int				i;
	double			ray_angle;

	col_id = 0;
	i = 0;
	ray_angle = player.rot_angle - (g_fov_angle / 2);
	while (i < g_num_rays)
	{
		g_rays[i].ray_angle = normalize_angle(ray_angle);
		ray_cast(col_id, ray_angle);
		draw_line(player.x, player.y, g_rays[i].hit_point.x, g_rays[i].hit_point.y, 0xFF0000);
		ray_angle = ray_angle + (g_fov_angle / g_num_rays);
		col_id++;
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

void				raycast_3d()
{
	draw_ceiling();
	draw_floor();
	draw_wall();
}

void				render()
{
	image_reset_2d();
	raycast_2d();
	raycast_3d();
}