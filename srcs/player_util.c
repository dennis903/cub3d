#include "../cub3d.h"

int					defence_seg_x(double angle)
{
	angle = normalize_angle(angle);
	if (angle > 0.5 * PI && angle < 1.5 * PI)
		return(-3);
	else if (angle <= 0.5 * PI || angle >= 1.5 * PI)
		return (3);
	return (0);
}

int					defence_seg_y(double angle)
{
	angle = normalize_angle(angle);
	if (angle > 0 && angle < PI)
		return (3);
	else if (angle >= 0 || angle >= PI)
		return (-3);
	return (0);
}

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
	if (!has_wall_at(new_pos_x + defence_seg_x(player.rot_angle),
	new_pos_y + defence_seg_y(player.rot_angle)))
	{
		player.x = new_pos_x;
		player.y = new_pos_y;
	}
}