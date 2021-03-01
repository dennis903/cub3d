#include "../cub3d.h"

void				render()
{
	img_reset_2d();
	img_reset_3d();
	ray_cast_2d();
	// ray_cast_3d();
}

int					main_loop(void)
{
	update();
	render();
	mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.img_2d.img, 0, 0);
	// mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.img_3d.img, 0, 0);
	return (0);
}