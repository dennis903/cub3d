#include "../cub3d.h"

void				horizontal_wall_check(double angle, t_point *horz_wall)
{
	int				angle_side_up;
	int				angle_side_left;
	t_point			intercept;
	t_point			step;
	t_point			next_horz_touch;

	angle = normalize_angle(angle);
	horz_wall -> is_wall = 0;
	angle_side_up = (angle <= 0 || angle >= PI) ? 1 : 0;
	angle_side_left = (angle >= 0.5 * PI && angle <= 1.5 * PI) ? 1 : 0;
	intercept.y = floor(player.y / g_tile_size) * g_tile_size;
	if (!angle_side_up)
		intercept.y += g_tile_size;
	intercept.x = player.x + ((intercept.y - player.y) / tan(angle));
	step.y = g_tile_size;
	if (angle_side_up)
		step.y *= -1;
	step.x = g_tile_size / tan(angle);
	if (angle_side_left && step.x > 0)
		step.x *= -1;
	if (!angle_side_left && step.x < 0)
		step.x *= -1;
	next_horz_touch.x = intercept.x;
	next_horz_touch.y = intercept.y;
	get_next_horz_touch(next_horz_touch, &horz_wall, step, angle_side_up);
}

void				vertical_wall_check(double angle, t_point *vert_wall)
{
	int				angle_side_up;
	int				angle_side_left;
	t_point			intercept;
	t_point			step;
	t_point			next_vert_touch;

	angle = normalize_angle(angle);
	vert_wall -> is_wall = 0;
	angle_side_up = (angle <= 0 || angle >= PI) ? 1 : 0;
	angle_side_left = (angle > 0.5 * PI && angle <= 1.5 * PI) ? 1 : 0;
	intercept.x = floor(player.x / g_tile_size) * g_tile_size;
	if (!angle_side_left)
		intercept.x += g_tile_size;
	intercept.y = player.y + ((intercept.x - player.x) / tan(angle));
	step.x = g_tile_size;
	step.y = g_tile_size * tan(angle);
	if (angle_side_left)
		step.x *= -1;
	if (angle_side_up && step.y > 0)
		step.x *= -1;
	if (!angle_side_up && step.y < 0)
		step.x *= -1;
	next_vert_touch.x = intercept.x;
	next_vert_touch.y = intercept.y;
	//error occured in vert_wall
	get_next_vert_touch(next_vert_touch, &vert_wall, step, angle_side_left);
}

void				ray_cast(int col_id, double angle)
{
	t_point			horz_wall;
	t_point			vert_wall;
	double			horz_dist;
	double			vert_dist;

	angle = normalize_angle(angle);
	col_id = 0;
	horizontal_wall_check(angle, &horz_wall);
	vertical_wall_check(angle, &vert_wall);
	if (horz_wall.is_wall == 0)
		horz_dist = 9999999;
	else
		horz_dist = get_distance(player.x, player.y, horz_wall.x, horz_wall.y);
	if (vert_wall.is_wall == 0)
		vert_dist = 9999999;
	else
		vert_dist = get_distance(player.x, player.y, vert_wall.x, vert_wall.y);
	if (horz_dist > vert_dist)
		get_ray_data(vert_dist, col_id, vert_wall);
	else
		get_ray_data(horz_dist, col_id, horz_wall);
}