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
	header[0] = 'B';
	header[1] = 'M';
	header[2] = size % 256;
	header[3] = (size / 256) % 256;
	header[4] = (size / (256 * 256)) % 256;
	header[5] = (size / (256 * 256 * 256)) % 256;
	header[10] = '6';
	header[14] = 40;
	header[18] = md.width % 256;
	header[19] = (md.width / 256) % 256;
	header[20] = (md.width / (256 * 256)) % 256;
	header[21] = (md.width / (256 * 256 * 256)) % 256;
	header[22] = md.height % 256;
	header[23] = (md.height / 256) % 256;
	header[24] = (md.height / (256 * 256)) % 256;
	header[25] = (md.height / (256 * 256 * 256)) % 256;
	header[26] = 1;
	header[28] = 24;
	i = 0;
	while (i < 54)
	{
		printf("%d : %d\n", i, header[i]);
		i++;
	}
}

int					make_bmp()
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
	i = md.height - 1;
	while (i > -1)
	{
		j = 0;
		while (j < md.width)
		{
			write(fd, &(game.img_3d.data[i * md.width + j]), 3);
			j++;
		}
		i--;
	}
	return (0);
}