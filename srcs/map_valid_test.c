#include "../cub3d.h"


int				up_test(char **map, int i, int j)
{
	while (i >= 0)
	{
		if (map[i][j] == '1')
			return (0);
		i--;
	}
	return (ERROR);
}

int				left_test(char **map, int i, int j)
{
	while (j >= 0)
	{
		if (map[i][j] == '1')
			return (0);
		j--;
	}
	return (ERROR);
}

int				right_test(char **map, int i, int j)
{
	while (j <= g_idx_width)
	{
		if (map[i][j] == '1')
			return (0);
		j++;
	}
	return (ERROR);
}

int				down_test(char **map, int i, int j)
{
	while(j <= g_idx_height)
	{
		if (map[i][j] == '1')
			return (0);
		i++;
	}
	return (ERROR);
}

int				map_valid_test(char **map, int i, int j)
{
	if ((up_test(map, i, j)) == -1)
		return (ERROR);
	if ((down_test(map, i, j)) == -1)
		return (ERROR);
	if ((left_test(map, i, j)) == -1)
		return (ERROR);
	if ((right_test(map, i, j)) == -1)
		return (ERROR);
	return (0);
}