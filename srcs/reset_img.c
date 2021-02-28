#include "../cub3d.h"

void				image_reset_2d()
{
	int				i;
	int				j;

	i = 0;
	while (i < md.height)
	{
		j = 0;
		while (j < md.width)
		{
			game.img.data[i * md.width + j] = 0x000000;
			j++;
		}
		i++;
	}
}