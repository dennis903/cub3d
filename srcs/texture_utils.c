#include "../cub3d.h"

void				is_dir_up(int left, int col_id)
{
	if (left)
	{
		if (((int)g_rays[col_id].hit_point.y % g_tile_size) == 0)
			g_dir.check_no = 1;
		else
			g_dir.check_we = 1;
	}
	else
	{
		if (((int)g_rays[col_id].hit_point.x % g_tile_size) == 0)
			g_dir.check_ea = 1;
		else
			g_dir.check_no = 1;
	}
}

void				is_dir_down(int left, int col_id)
{
	if (left)
	{
		if (((int)g_rays[col_id].hit_point.y % g_tile_size) == 0)
			g_dir.check_so = 1;
		else
			g_dir.check_we = 1;
	}
	else
	{
		if (((int)g_rays[col_id].hit_point.x % g_tile_size) == 0)
			g_dir.check_ea = 1;
		else
			g_dir.check_so = 1;
	}
}