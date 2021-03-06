#include "../cub3d.h"

int					calc_bmp_size()
{
	int				padding;
	int				size;

	padding = 4 - (((md.width * 3) % 4) % 4);
	size = md.height * (md.width * 3 + padding);
	return (size);
}