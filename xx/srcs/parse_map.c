#include "../cub3d.h"

int				get_map_width(t_list *map_list)
{
	int			width;
	int			max_width;

	width = 0;
	max_width = 0;
	while (map_list)
	{
		width = ft_strlen((char *)map_list->content);
		if (width >= max_width)
			max_width = width;
		map_list = map_list->next;
	}
	return (max_width);
}

int				get_map_height(t_list *map_list)
{
	int			height;

	height = 0;
	while (map_list)
	{
		height++;
		map_list = map_list->next;
	}
	return (height);
}

void			parse_map(int fd, t_list **map_list)
{
	char		*line;

	line = 0;
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(map_list, ft_lstnew((void *)line));
}

char			**fill_map_data(t_list *map_list)
{
	char		**map;
	int			i;

	map = 0;
	g_idx_width = get_map_width(map_list);
	g_idx_height = get_map_height(map_list);
	if (g_idx_width == 0 || g_idx_height == 0)
		return (0);
	if (!(map = (char **)malloc(sizeof(char *) * g_idx_height)))
		return (0);
	i = 0;
	while (i < g_idx_height)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (g_idx_width + 1))))
			return (0);
		i++;
	}
	copy_map_data(map, map_list);
	if ((map_valid_check(map)) == ERROR)
	{
		i = 0;
		while (i < g_idx_height)
		{
			free(map[i]);
			i++;
		}
		return (0);
	}
	return (map);
}