#include "../cub3d.h"

int						get_texture_color(double x, double y)
{
	int					color;

	color = 0;
	if (g_dir.check_no == 1)
		color = g_dir.no_data[(int)(y * (g_dir.no_w)) + (int)x];
	else if (g_dir.check_so == 1)
		color = g_dir.so_data[(int)(y * (g_dir.so_w)) + (int)x];
	else if (g_dir.check_ea == 1)
		color = g_dir.ea_data[(int)(y * (g_dir.ea_w)) + (int)x];
	else if (g_dir.check_we == 1)
		color = g_dir.we_data[(int)(y * (g_dir.we_w)) + (int)x];
	return (color);
}