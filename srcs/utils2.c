#include "../cub3d.h"

int					calc_idx(int x, int y)
{
	return (y * (g_tile_size * g_idx_width) + x);
}