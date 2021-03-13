/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:53 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 17:21:27 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				set_bmp_header(unsigned char *header)
{
	int				size;
	int				i;

	size = calc_bmp_size();
	i = 0;
	while (i < 54)
	{
		header[i] = 0;
		i++;
	}
	fill_header(header, size);
}

void				fill_header(unsigned char *header, int size)
{
	header[0] = 'B';
	header[1] = 'M';
	header[2] = size % 256;
	header[3] = (size / 256) % 256;
	header[4] = (size / (256 * 256)) % 256;
	header[5] = (size / (256 * 256 * 256)) % 256;
	header[10] = '6';
	header[14] = 40;
	header[18] = g_md.width % 256;
	header[19] = (g_md.width / 256) % 256;
	header[20] = (g_md.width / (256 * 256)) % 256;
	header[21] = (g_md.width / (256 * 256 * 256)) % 256;
	header[22] = g_md.height % 256;
	header[23] = (g_md.height / 256) % 256;
	header[24] = (g_md.height / (256 * 256)) % 256;
	header[25] = (g_md.height / (256 * 256 * 256)) % 256;
	header[26] = 1;
	header[28] = 24;
}

int					make_bmp(void)
{
	int				fd;
	int				i;
	int				j;
	unsigned char	header[54];

	set_bmp_header(&header[0]);
	if (!(fd = open("screenshot.bmp", O_RDWR | O_APPEND | O_CREAT | O_TRUNC, 00777)))
		return (ERROR);
	i = 0;
	while (i < 54)
	{
		write(fd, &header[i], sizeof(header[i]));
		i++;
	}
	i = g_md.height - 1;
	while (i > -1)
	{
		j = -1;
		while (j++ < g_md.width)
			write(fd, &(g_game.img_3d.data[i * g_md.width + j]), 3);
		i--;
	}
	return (0);
}
