#include "../cub3d.h"

double				get_degree(int degree)
{
	return (degree * (PI / 180));
}

int					has_wall_at(double x, double y)
{
	int				check_wall_x;
	int				check_wall_y;

	if (x > md.width || x < 0 || y > md.height || y < 0)
		return (1);
	check_wall_x = floor(x / g_tile_size);
	check_wall_y = floor(y / g_tile_size);
	if (game.map[check_wall_x][check_wall_y] == 0)
		return (0);
	else
		return (1);
}

int					to_coord(double x, double y)
{
	return ((int)(floor(x * md.width) + floor(y)));
}