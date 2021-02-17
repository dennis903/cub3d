#include "cub3d.h"

int				main(int argc, char *argv[])
{
	int			fd;

	if (argc != 2)
		return (ERROR);
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		printf("file open error\n");
		return (ERROR);
	}
	if (parse_cub(fd) == ERROR)
	{
		printf("cub parse error\n");
		return (ERROR);
	}
	if (cub_setting() == ERROR)
	{
		printf("cub setting error\n");
		return (ERROR);
	}
	mlx_loop_hook(game.mlx, &main_loop, 0);
	mlx_loop(game.mlx);
	return (0);
}