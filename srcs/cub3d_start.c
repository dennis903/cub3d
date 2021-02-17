#include "../cub3d.h"

int				main_loop(void)
{
	update();
	render();
	mlx_put_image_to_window(game.mlx, game.win, game.img.img, 0, 0);
	return (0);
}