#include "../cub3d.h"

void				sprite_2d()
{
	int				i;
	double			pbs_angle;
	i = 0;

	while (i < g_sprite_num)
	{
		g_sprites[i].visible = 0;
		pbs_angle = player.rot_angle - atan2(g_sprites[i].pos.y - player.y, g_sprites[i].pos.x - player.x);
		if (pbs_angle > PI)
			pbs_angle -= PI * 2;
		if (pbs_angle < -PI)
			pbs_angle += (PI * 2);
		pbs_angle = fabs(pbs_angle);
		if (pbs_angle < g_fov_angle / 2)
		{
			g_sprites[i].visible = 1;
			draw_2d_sprite((int)g_sprites[i].pos.y, (int)g_sprites[i].pos.x, 0xF100FF);
		}
		else
			draw_2d_sprite((int)g_sprites[i].pos.y, (int)g_sprites[i].pos.x, 0x3b3b3b);
		i++;
	}
}