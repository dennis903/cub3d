/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:31:09 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 15:49:44 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				check_g_md(void)
{
	if (g_md.width != 0 && g_md.height != 0)
		return (ERROR);
	return (0);
}

int				check_texture(char *splits)
{
	if (ft_strcmp(splits, "NO") == 0)
	{
		if (g_md.north != 0)
			return (ERROR);
	}
	else if (ft_strcmp(splits, "SO") == 0)
	{
		if (g_md.south != 0)
			return (ERROR);
	}
	else if (ft_strcmp(splits, "EA") == 0)
	{
		if (g_md.east != 0)
			return (ERROR);
	}
	else if (ft_strcmp(splits, "WE") == 0)
	{
		if (g_md.west != 0)
			return (ERROR);
	}
	return (0);
}

int				check_sprite(char *splits)
{
	if (ft_strcmp(splits, "S") == 0)
	{
		if (g_md.sprite != 0)
			return (ERROR);
	}
	return (0);
}

int				check_comma(char *splits)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (splits[i])
	{
		if (count > 2)
			return (ERROR);
		if (splits[i] == ',')
			count++;
		i++;
	}
	return (0);
}

int				check_color(char *splits, char *splits2)
{
	if (ft_strcmp(splits, "F"))
	{
		if (check_comma(splits2) == ERROR)
			return (ERROR);
	}
	else if (ft_strcmp(splits, "C"))
	{
		if (check_comma(splits2) == ERROR)
			return (ERROR);
	}
	return (0);
}
