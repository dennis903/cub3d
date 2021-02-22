#include "../cub3d.h"

double				get_degree(int degree)
{
	return (degree * (PI / 180));
}

int					has_wall_at(double x, double y)
{
	int				check_wall_x;
	int				check_wall_y;

	if (x >= g_map_width || x < 0 || y >= g_map_height || y < 0)
		return (1);
	check_wall_x = floor(x / g_tile_size);
	check_wall_y = floor(y / g_tile_size);
	if (game.map[check_wall_y][check_wall_x] == '1')
		return (1);
	else
		return (0);
}

int					to_coord(double x, double y)
{
	return ((int)floor(y) * g_map_width + (int)floor(x));
}

double				get_distance(int x1, int y1, int x2, int y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}