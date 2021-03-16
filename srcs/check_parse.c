/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 01:31:09 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 02:02:15 by ihyeongjin       ###   ########.fr       */
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
	else if (ft_strcmp(splits, "S") == 0)
	{
		if (g_md.sprite != 0)
			return (ERROR);
	}
	return (0);
}

int				check_color(char *splits)
{
	if (ft_strcmp(splits, "F"))
	{
		if (g_md.f != 0)
			return (ERROR);
	}
	else if (ft_strcmp(splits, "C"))
	{
		if (g_md.c != 0)
			return (ERROR);
	}
	return (0);
}