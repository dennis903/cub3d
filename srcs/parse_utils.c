#include "../cub3d.h"

int				count_splits(char **splits)
{
	int			count;

	count = 0;
	while (splits[count])
		count++;
	return (count);
}

int				set_base_data(char **splits)
{
	int			split_length;

	split_length = count_splits(splits);
	if (split_length != 2)
		return (ERROR);
	if (ft_strcmp(splits[0], "R") == 0)
		return (save_r(splits));
	else if (ft_strcmp(splits[0], "NO") == 0)
		return (save_texture(splits));
	else if (ft_strcmp(splits[0], "SO") == 0)
		return (save_texture(splits));
	else if (ft_strcmp(splits[0], "EA") == 0)
		return (save_texture(splits));
	else if (ft_strcmp(splits[0], "WE") == 0)
		return (save_texture(splits));
	else if (ft_strcmp(splits[0], "S") == 0)
		return (save_texture(splits));
	else if (ft_strcmp(splits[0], "F") == 0)
		return (save_color(splits));
	else if (ft_strcmp(splits[0], "c") == 0)
		return (save_color(splits));
	return (0);
}

int				make_color(char *splits, t_color **color)
{
	int			split_length;
	char		**sub_split;
	t_color		*temp;

	sub_split = ft_split(splits, ',');
	split_length = count_splits(sub_split);
	if (split_length != 3)
		return (ERROR);
	if (!(temp = (t_color *)malloc(sizeof(t_color))))
		return (ERROR);
	*color = temp;
	(*color)->red = ft_atoi(sub_split[0]);
	(*color)->green = ft_atoi(sub_split[1]);
	(*color)->blue = ft_atoi(sub_split[2]);
	return (0);
}

void			free_arrs(char **splits)
{
	int			i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
}