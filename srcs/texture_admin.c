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