#include "../cub3d.h"

unsigned int				fill_color(t_color *color)
{
	int						r;
	int						g;
	int						b;

	r = color->red;
	g = color->green;
	b = color->blue;
	return (((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF)); 
}