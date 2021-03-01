#include "../cub3d.h"

void				horizontal_wall_check(double angle, t_point *horz_wall)
{
	int				side_up;
	int				side_left;
	t_point			intercept;
	t_point			step;

	horz_wall->is_wall = 0;
	side_up = 0;
	side_left = 0;
	if (angle <= 0 || angle >= PI)
		side_up = 1;
	if (angle >= 0.5 * PI && angle <= 1.5 * PI)
		side_left = 1;
	intercept.y = floor(g_player.y / g_tile_size) * g_tile_size;
	if (!side_up)
		intercept.y += g_tile_size;
	intercept.x = g_player.x + (intercept.y - g_player.y) / tan(angle);
	step.y = g_tile_size;
	if (side_up)
		step.y *= -1;
	step.x = g_tile_size / tan(angle);
	if (side_left && step.x > 0)
		step.x *= -1;
	if (!side_left && step.x < 0)
		step.x *= -1;
	get_next_horz_touch(intercept, &horz_wall, step, side_up);
}

void				vertical_wall_check(double angle, t_point *vert_wall)
{
	int				side_down;
	int				side_left;
	t_point			intercept;
	t_point			step;

	vert_wall->is_wall = 0;
	side_down = 0;
	side_left = 0;
	if (angle > 0 && angle < PI)
		side_down = 1;
	if (angle > 0.5 * PI && angle <= 1.5 * PI)
		side_left = 1;
	intercept.x = floor(g_player.x / g_tile_size) * g_tile_size;
	if (!side_left)
		intercept.x += g_tile_size;
	intercept.y = g_player.y + ((intercept.x - g_player.x) * tan(angle));
	step.x = g_tile_size;
	step.y = g_tile_size * tan(angle);
	if (side_left)
		step.x *= -1;
	if (!side_down && step.y > 0)
		step.y *= -1;
	if (side_down && step.y < 0)
		step.y *= -1;
	if (side_left)
		intercept.x--;
	get_next_vert_touch(intercept, &vert_wall, step, side_left);
}

void				ray_cast(int col_id, double ray_angle)
{
	t_point			horz_wall;
	t_point			vert_wall;
	double			horz_dist;
	double			vert_dist;

	ray_angle = normalize_angle(ray_angle);
	horizontal_wall_check(ray_angle, &horz_wall);
	vertical_wall_check(ray_angle, &vert_wall);
	if (horz_wall.is_wall == 0)
		horz_dist = 99999999;
	else
		horz_dist = get_distance(g_player.x, g_player.y, horz_wall.x, horz_wall.y);
	if (vert_wall.is_wall == 0)
		vert_dist = 99999999;
	else
		vert_dist = get_distance(g_player.x, g_player.y, vert_wall.x, vert_wall.y);
	if (horz_dist > vert_dist)
		get_ray_data(vert_dist, col_id, vert_wall);
	else
		get_ray_data(horz_dist, col_id, horz_wall);
}

void				draw_2d_ray()
{
	int				col_id;
	int				i;
	double			ray_angle;

	col_id = 0;
	i = 0;
	ray_angle = g_player.rot_angle;// - (g_fov_angle / 2);
	while (i < 1)
	{
		g_rays[i].angle = normalize_angle(ray_angle);
		ray_cast(col_id, ray_angle);
		printf("%lf %lf\n", g_rays[i].hit_point.x, g_rays[i].hit_point.y);
		draw_line(g_player.x, g_player.y, g_rays[i].hit_point.x, g_rays[i].hit_point.y);
		ray_angle = ray_angle + (g_fov_angle / g_num_rays);
		col_id++;
		i++;
	}
}

void				ray_cast_2d()
{
	draw_rectangles();
	draw_lines();
	draw_player();
	draw_2d_ray();
}