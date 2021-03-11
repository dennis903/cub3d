#include "../cub3d.h"

int					calc_idx(int x, int y)
{
	return (y * (g_tile_size * g_idx_width) + x);
}

int					count_sprite()
{
	int			i;
	int			j;
	int			count;

	i = 0;
	count = 0;
	while (i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (game.map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_ray					rot_angle_ray_cast(double angle)
{
	t_point				horz_wall;
	t_point				vert_wall;
	t_ray				ray;
	double				horz_dist;
	double				vert_dist;

	angle = normalize_angle(angle);
	ray.ray_angle = angle;
	horizontal_wall_check(angle, &horz_wall);
	ray.side = 0;
	vertical_wall_check(angle, &vert_wall);
	if (horz_wall.is_wall == 0)
		horz_dist = 9999999;
	else
		horz_dist = get_distance(player.x, player.y, horz_wall.x, horz_wall.y);
	if (vert_wall.is_wall == 0)
		vert_dist = 9999999;
	else
		vert_dist = get_distance(player.x, player.y, vert_wall.x, vert_wall.y);
	if (horz_dist >= vert_dist)
		ray.side = 1;
	return (ray);
}

double					fix_angle(double angle)
{
	if (g_keys.a_key)
		angle = angle + get_degree(90);
	else if (g_keys.d_key)
		angle = angle + get_degree(270);
	else if (g_keys.s_key)
		angle = angle + get_degree(180);
	return (angle);
}
double					check_angle_by_dir(double angle)
{
	if (g_keys.a_key)
		angle = angle - get_degree(90);
	else if (g_keys.d_key)
		angle = angle + get_degree(90);
	else if (g_keys.s_key)
		angle = angle + get_degree(180);
	return (angle);
}