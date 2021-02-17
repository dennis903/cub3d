#include "../cub3d.h"

void			copy_map_data(char **map, t_list *map_list)
{
	int			length;
	int			i;
	int			j;

	i = 0;
	while (map_list)
	{
		length = ft_strlen((char *)map_list->content);
		j = 0;
		while (j < length)
		{
			map[i][j] = ((char *)(map_list->content))[j];
			j++;
		}
		i++;
		map_list = map_list->next;
	}
}

int				map_valid_check(char **map)
{
	int			i;
	int			j;

	i = 0;
	while (i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (map[i][j] == '0' || map[i][j] == '2' || map[i][j] == 'N' ||
			 map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S')
				if ((map_valid_test(map, i, j)) == -1)
			 		return (ERROR);
			j++;
		}
		i++;
	}
	return (0);
}