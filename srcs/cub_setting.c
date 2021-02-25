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

void			ray_setting()
{
	g_fov_angle = get_degree(60);
	g_num_rays = g_map_width;
	if (!(g_rays = (t_ray *)malloc(sizeof(t_ray) * g_num_rays)))
		exit(1);
	if (g_num_rays == 0)
		exit(1);
}

int				cub_setting()
{
	if (!(game.win = mlx_new_window(game.mlx, g_map_width, g_map_height, "cub3d")))
		return (ERROR);
	if (!(game.img.img = mlx_new_image(game.mlx, 
	g_map_width, g_map_height)))
		return (ERROR);
	game.img.data = (int *)mlx_get_data_addr(game.img.img, &(game.img.bpp), &(game.img.size_l), &(game.img.endian));
	// if ((get_texture(g_dir.north) == ERROR))
	// 	return (ERROR);
	// if ((get_texture(g_dir.south) == ERROR))
	// 	return (ERROR);
	// if ((get_texture(g_dir.east) == ERROR))
	// 	return (ERROR);
	// if ((get_texture(g_dir.west) == ERROR))
	// 	return (ERROR);
	player_setting();
	ray_setting();
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, key_press, 0);
	mlx_hook(game.win, X_EVENT_KEY_release, 0, key_release, 0);
	return (0);
}