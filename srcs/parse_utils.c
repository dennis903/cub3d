/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:26 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 01:46:11 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				count_splits(char **splits)
{
	int			count;

	count = 0;
	while (splits[count])
		count++;
	return (count);
}

int				test_color_num(char *s1, char *s2, char *s3)
{
	int			i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] < '0' || s1[i] > '9')
			return (ERROR);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (s2[i] < '0' || s2[i] > '9')
			return (ERROR);
		i++;
	}
	i = 0;
	while (s3[i])
	{
		if (s3[i] < '0' || s3[i] > '9')
			return (ERROR);
		i++;
	}
	return (0);
}

int				set_base_data(char **splits)
{
	int			split_length;

	split_length = count_splits(splits);
	if (split_length != 2 && split_length != 3)
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
	else if (ft_strcmp(splits[0], "C") == 0)
		return (save_color(splits));
	return (0);
}

int				make_color(char *splits, t_color **color)
{
	int			split_length;
	char		**sub_split;
	t_color		*temp;

	if ((*color) != 0)
		return (ERROR);
	sub_split = ft_split(splits, ',');
	split_length = count_splits(sub_split);
	if (split_length != 3)
		return (ERROR);
	if (test_color_num(sub_split[0], sub_split[1], sub_split[2]) == ERROR)
		return (ERROR);
	if (!(temp = (t_color *)malloc(sizeof(t_color))))
	{
		free(temp);
		return (ERROR);
	}
	*color = temp;
	(*color)->red = ft_atoi(sub_split[0]);
	(*color)->green = ft_atoi(sub_split[1]);
	(*color)->blue = ft_atoi(sub_split[2]);
	if ((*color)->red > 255 || ((*color)->green > 255 || (*color)->blue > 255))
		return (ERROR);
	free_arrs(sub_split);
	return (0);
}

void			free_arrs(char **splits)
{
	int			i;

	if (!(*splits))
		return ;
	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}
