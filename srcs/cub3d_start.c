#include "../cub3d.h"

int				main_loop(void)
{
	
	update();
	render();
	// mlx_put_image_to_window(game.mlx, game.win, game.img_2d.img, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img_3d.img, 0, 0);
	return (0);
}