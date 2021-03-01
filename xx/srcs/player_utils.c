#include "../cub3d.h"

void				set_angle(char direction)
{
	if (direction == 'N')
		g_player.rot_angle = (PI / 180) * 90;
	else if (direction == 'E')
		g_player.rot_angle = PI / 180;
	else if (direction == 'W')
		g_player.rot_angle = PI;
	else if (direction == 'S')
		g_player.rot_angle = (PI / 180) * 270;
}

void				player_init(int height, int width)
{
	g_player.x = g_tile_size * width;
	g_player.y = g_tile_size * height;
	g_player.radius = 3;
	g_player.turn_dir = 0;
	g_player.walk_dir = 0;
	g_player.move_speed = 2.0;
	g_player.rotation_speed = 2 * (PI / 180);
}

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

	g_player.rot_angle += g_player.turn_dir * g_player.rotation_speed;
	movestep = g_player.move_speed * g_player.walk_dir;
	new_pos_x = g_player.x;
	new_pos_y = g_player.y;

	if (g_keys.w_key == 1 || g_keys.s_key == 1)
	{
		new_pos_x = g_player.x + cos(g_player.rot_angle) * movestep;
		new_pos_y = g_player.y + sin(g_player.rot_angle) * movestep;
	}
	else if (g_keys.a_key == 1 || g_keys.d_key == 1)
	{
		new_pos_x = g_player.x + cos(g_player.rot_angle - (PI / 180) * 90) * movestep;
		new_pos_y = g_player.y + sin(g_player.rot_angle - (PI / 180) * 90) * movestep;
	}
	if (!has_wall_at(new_pos_x + defence_seg_x(g_player.rot_angle),
	new_pos_y + defence_seg_y(g_player.rot_angle)))
	{
		g_player.x = new_pos_x;
		g_player.y = new_pos_y;
	}
}