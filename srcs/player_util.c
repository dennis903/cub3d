#include "../cub3d.h"

void				update(void)
{
	double			movestep;
	double			new_pos_x;
	double			new_pos_y;

	player.rot_angle += player.turn_dir * player.rotation_speed;
	movestep = player.move_speed * player.walk_dir;
	new_pos_x = player.x;
	new_pos_y = player.y;

	if (g_keys.w_key == 1 || g_keys.s_key == 1)
	{
		new_pos_x = player.x + cos(player.rot_angle) * movestep;
		new_pos_y = player.y + sin(player.rot_angle) * movestep;
	}
	else if (g_keys.a_key == 1 || g_keys.d_key == 1)
	{
		new_pos_x = player.x + cos(player.rot_angle - get_degree(90)) * movestep;
		new_pos_y = player.y + sin(player.rot_angle - get_degree(90)) * movestep;
	}
	if (!has_wall_at(new_pos_x, new_pos_y))
	{
		player.x = new_pos_x;
		player.y = new_pos_y;
	}
}