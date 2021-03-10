#include "../cub3d.h"

void				set_angle(char direction)
{
	if (direction == 'N')
		player.rot_angle = (PI / 180) * 270;
	else if (direction == 'E')
		player.rot_angle = PI / 180;
	else if (direction == 'W')
		player.rot_angle = PI;
	else if (direction == 'S')
		player.rot_angle = (PI / 180) * 90;
}

void				player_init(int height, int width)
{
	player.x = g_tile_size * width;
	player.y = g_tile_size * height;
	player.radius = 3;
	player.turn_dir = 0;
	player.walk_dir = 0;
	player.move_speed = 2.0;
	player.rotation_speed = 2 * (PI / 180);
}

int					defence_seg_x(double angle)
{
	t_ray			ray;
	int				side_down;
	int				side_left;

	side_down = 0;
	side_left = 0;
	angle = fix_angle(angle);
	if (angle > 0 && angle < PI)
		side_down = 1;
	if (angle > 0.5 * PI && angle < 1.5 * PI)
		side_left = 1;
	ray = rot_angle_ray_cast(angle);
	if (ray.side == 0 && side_down == 1)
		return (0);
	if (ray.side == 0 && !(side_down))
		return (0);
	if (ray.side == 1 && side_left)
		return (3);
	else
		return (-3);
}

int					defence_seg_y(double angle)
{
	t_ray			ray;
	int				side_down;
	int				side_left;

	side_down = 0;
	side_left = 0;
	angle = fix_angle(angle);
	if (angle > 0 && angle < PI)
		side_down = 1;
	if (angle > 0.5 * PI && angle < 1.5 * PI)
		side_left = 1;
	ray = rot_angle_ray_cast(angle);
	if (ray.side == 0 && side_down == 1)
		return (3);
	if (ray.side == 0 && !(side_down))
		return (-3);
	if (ray.side == 1 && side_left)
		return (0);
	else
		return (0);
}

void				update(void)
{
	double			movestep;
	double			new_pos_x;
	double			new_pos_y;

	player.rot_angle += player.turn_dir * player.rotation_speed;
	player.rot_angle = normalize_angle(player.rot_angle);
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