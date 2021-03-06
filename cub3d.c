/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:51:57 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 20:37:57 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					find_str(char *dist, const char *src)
{
	int				i;
	int				j;

	i = 0;
	while (dist[i])
	{
		if (dist[i] == src[0])
		{
			j = 0;
			while (dist[i] == src[j] && src[j])
			{
				j++;
				i++;
			}
			if (!src[j] && !dist[i])
			{
				return (1);
			}
		}
		else
			i++;
	}
	printf(".cub error\n");
	return (ERROR);
}

int					check_save(char *argv)
{
	int				fd;

	if (find_str(argv, ".cub") == ERROR)
		return (ERROR);
	if (!(fd = open(argv, O_RDONLY)))
	{
		printf("file open error\n");
		return (ERROR);
	}
	if (parse_cub(fd) == ERROR)
	{
		printf("cub parse error\n");
		return (ERROR);
	}
	if (cub_setting() == ERROR)
	{
		printf("cub setting error\n");
		return (ERROR);
	}
	update();
	render();
	if (make_bmp() == ERROR)
		return (ERROR);
	return (0);
}

int					display_window(char *argv)
{
	int			fd;

	if (find_str(argv, ".cub") == ERROR)
		return (ERROR);
	if (!(fd = open(argv, O_RDONLY)))
	{
		printf("file open error\n");
		return (ERROR);
	}
	if (parse_cub(fd) == ERROR)
	{
		printf("cub parse error\n");
		return (ERROR);
	}
	if (cub_setting() == ERROR)
	{
		printf("cub setting error\n");
		return (ERROR);
	}
	mlx_loop_hook(g_game.mlx, main_loop, 0);
	mlx_loop(g_game.mlx);
	return (0);
}

int					main(int argc, char *argv[])
{
	if (argc != 2 && argc != 3)
	{
		printf("please type --save or .cub\n");
		return (ERROR);
	}
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
		{
			if (check_save(argv[1]) == ERROR)
			{
				printf("save_error\n");
				return (ERROR);
			}
		}
		else
		{
			printf("save_error\n");
			return (ERROR);
		}
	}
	if (argc == 2)
		if (display_window(argv[1]) == ERROR)
			return (ERROR);
	return (0);
}
