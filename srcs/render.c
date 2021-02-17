#include "../cub3d.h"

void				draw_2d_ray()
{
	int				col_id;
	int				i;
	double			ray_angle;

	col_id = 0;
	i = 0;
	ray_angle = player.rot_angle - get_degree(FOV_ANGLE / 2);
	while (i < md.width)
	{
		rays[i].ray_angle = normalize_angle(ray_angle);
		ray_cast(col_id, ray_angle);
		draw_line(player.x, player.y, rays[i].hit_point.x, rays[i].hit_point.y, 0xFF0000);
		ray_angle = ray_angle + (FOV_ANGLE / md.width);
		col_id++;
		i++;
	}
}

void				image_reset()
{
	int				i;
	int				j;

	i = 0;
	while (i < md.height)
	{
		j = 0;
		while (j < md.width)
		{
			game.img.data[i * md.width + j] = 0x000000;
			j++;
		}
		i++;
	}
}

void				raycast_2d()
{
	draw_player();
	draw_rectangles();
	draw_lines();
//	draw_2d_ray();
}

void				render()
{
	image_reset();
	raycast_2d();
}