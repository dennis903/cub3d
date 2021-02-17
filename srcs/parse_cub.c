#include "../cub3d.h"

int				data_setting(char *line)
{
	char		**splits;

	splits = ft_split(line, ' ');
	if (*splits == 0)
	{
		free_arrs(splits);
		return (0);
	}
	else
	{
		if (set_base_data(splits) == ERROR)
		{
			free_arrs(splits);
			return (-1);
		}
	}
	free_arrs(splits);
	return (1);
}

int				data_check()
{
	if (md.width == 0 || md.height == 0 || md.north == 0 || md.south == 0 ||
	md.east == 0 || md.west == 0 || md.sprite == 0 || md.f == 0 || md.c == 0)
		return (-1);
	return (SUCCESS);
}

int				parse_data(int fd)
{
	char		*line;

	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		//error in data_setting
		if (data_setting(line) == ERROR)
		{
			free(line);
			return (ERROR);
		}
		if (data_check() == SUCCESS)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (0);
}

int				move_to_map(int fd, t_list **map_list)
{
	int			check;
	char		*line;

	check = 0;
	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\0')
		{
			check = 1;
			free(line);
			break ;
		}
		free(line);
	}
	if (check == 0)
		return (ERROR);
	ft_lstadd_back(map_list, ft_lstnew((void *)line));
	parse_map(fd, map_list);
	return (0);
}

int				parse_cub(int fd)
{
	int			w_tile;
	int			h_tile;
	t_list		*map_list;

	map_list = 0;
	if (!(game.mlx = mlx_init()))
		return (ERROR);
	if (parse_data(fd) == ERROR)
		return (ERROR);
	if (move_to_map(fd, &map_list) == ERROR)
		return (ERROR);
	if ((game.map = fill_map_data(map_list)) == 0)
		return (ERROR);
	w_tile = md.width / g_idx_width;
	h_tile = md.height / g_idx_height;
	if (w_tile >= h_tile)
		g_tile_size = h_tile;
	else
		g_tile_size = w_tile;
	return (0);
}