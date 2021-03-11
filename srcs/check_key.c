#include "../cub3d.h"

void			check_w(double angle)
{
	t_point		new_pos;

	new_pos.x = (player.x + cos(angle) * player.move_speed);
	new_pos.y = (player.y + sin(angle) * player.move_speed);
	if (!has_wall_at(new_pos.x + defence_seg_x(player.rot_angle),
new_pos.y + defence_seg_y(player.rot_angle)))
	{
		player.x = new_pos.x;
		player.y = new_pos.y;
	}
}

void			check_s(double angle)
{
	t_point		new_pos;

	angle += get_degree(180);
	new_pos.x = (player.x + cos(angle) * player.move_speed);
	new_pos.y = (player.y + sin(angle) * player.move_speed);
	if (!has_wall_at(new_pos.x + defence_seg_x(player.rot_angle),
new_pos.y + defence_seg_y(player.rot_angle)))
	{
		player.x = new_pos.x;
		player.y = new_pos.y;
	}
}

void			check_d(double angle)
{
	t_point		new_pos;

	angle += get_degree(90);
	new_pos.x = (player.x + cos(angle) * player.move_speed);
	new_pos.y = (player.y + sin(angle) * player.move_speed);
	if (!has_wall_at(new_pos.x + defence_seg_x(player.rot_angle),
new_pos.y + defence_seg_y(player.rot_angle)))
	{
		player.x = new_pos.x;
		player.y = new_pos.y;
	}
}

void			check_a(double angle)
{
	t_point		new_pos;

	angle += get_degree(270);
	new_pos.x = (player.x + cos(angle) * player.move_speed);
	new_pos.y = (player.y + sin(angle) * player.move_speed);
	if (!has_wall_at(new_pos.x + defence_seg_x(player.rot_angle),
new_pos.y + defence_seg_y(player.rot_angle)))
	{
		player.x = new_pos.x;
		player.y = new_pos.y;
	}
}