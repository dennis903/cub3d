#include "../cub3d.h"

void			get_next_horz_touch(t_point touch, t_point **horz_wall, t_point step, int angle_side_up)
{
	while (touch.x >= 0 && touch.x <= g_map_width && touch.y >= 0 && touch.y <= g_map_height)
	{
		if (has_wall_at(touch.x, touch.y - angle_side_up))
		{
			(*horz_wall)->is_wall = 1;
			(*horz_wall)->x = touch.x;
			(*horz_wall)->y = touch.y;
			break ;
		}
		else
		{
			touch.x += step.x;
			touch.y += step.y;
		}
	}
}

void				get_next_vert_touch(t_point touch, t_point **vert_wall, t_point step, int angle_side_left)
{
	while (touch.x >= 0 && touch.x <= g_map_width && touch.y >= 0 && touch.y <= g_map_height)
	{
		if (has_wall_at(touch.x - angle_side_left, touch.y))
		{
			(*vert_wall)->is_wall = 1;
			(*vert_wall)->x = touch.x;
			(*vert_wall)->y = touch.y;
			break ;
		}
		else
		{
			touch.x += step.x;
			touch.y += step.y;
		}
	}
}

void				get_ray_data(double dist, int col_id, t_point wall_point)
{
	g_rays[col_id].distance = dist;
	g_rays[col_id].hit_point.x = wall_point.x;
	g_rays[col_id].hit_point.y = wall_point.y;
}