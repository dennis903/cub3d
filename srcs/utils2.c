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