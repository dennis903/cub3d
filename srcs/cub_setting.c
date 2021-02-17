#include "../cub3d.h"

void			set_angle(char direction)
{
	if (direction == 'N')
		player.rot_angle = (PI / 180) * get_degree(90);
	else if (direction == 'E')
		player.rot_angle = PI / 180;
	else if (direction == 'W')
		player.rot_angle = PI;
	else if (direction == 'S')
		player.rot_angle = (PI / 180) * get_degree(270);
}

void			player_init(int height, int width)
{
	player.x = g_tile_size * width;
	player.y = g_tile_size * height;
	player.radius = 3;
	player.turn_dir = 0;
	player.walk_dir = 0;
	player.move_speed = 2.0;
	player.rotation_speed = 2 * (PI / 180);
}

void			player_setting()
{
	int			i;
	int			j;

	i = 0;
	while (i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (game.map[i][j] == 'N' || game.map[i][j] == 'S'
			|| game.map[i][j] == 'W' || game.map[i][j] == 'E')
			{
				set_angle(game.map[i][j]);
				player_init(i, j);
			}
			j++;
		}
		i++;
	}
}

int				cub_setting()
{
	if (!(game.win = mlx_new_window(game.mlx, md.width, md.height, "cub3d")))
		return (ERROR);
	if (!(game.img.img = mlx_new_image(game.mlx, 
	g_idx_width * g_tile_size, g_idx_height * g_tile_size)))
		return (ERROR);
	game.img.img = mlx_get_data_addr(game.img.img, &(game.img.bpp), &(game.img.size_l), &(game.img.endian));
	player_setting();
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, key_press, 0);
	mlx_hook(game.win, X_EVENT_KEY_release, 0, key_release, 0);
	return (0);
}