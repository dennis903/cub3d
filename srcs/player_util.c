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

	angle = check_angle_by_dir(angle);
	ray = rot_angle_ray_cast(angle);
	check_direction(ray);
	if (g_dir.check_ea)
		return (3);
	else if (g_dir.check_we)
		return (-3);
	return (0);
}

int					defence_seg_y(double angle)
{
	t_ray			ray;
	
	angle = check_angle_by_dir(angle);
	ray = rot_angle_ray_cast(angle);
	check_direction(ray);
	if (g_dir.check_no)
		return (-3);
	else if (g_dir.check_so)
		return (3);
	return (0);
}

void				update(void)
{
	player.rot_angle += player.turn_dir * player.rotation_speed;
	player.rot_angle = normalize_angle(player.rot_angle);
	move_player();
}