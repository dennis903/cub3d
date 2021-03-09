#include "../cub3d.h"

void					draw_2d_sprite(int y, int x, int color)
{
	int					i;
	int					j;

	i = 0;

	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			game.img_2d.data[(y + i) * (g_tile_size * g_idx_width) + x + j] = color;
			j++;
		}
		i++;
	}
}

void					sprite_pos_set()
{
	int					i;
	int					j;
	int					count;

	count = 0;
	i = 0;
	while(i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (game.map[i][j] == '2')
			{
				g_sprites[count].pos.x = j * g_tile_size;
				g_sprites[count].pos.y = i * g_tile_size;
				count++;
			}
			j++;
		}
		i++;
	}
}

void					draw_sprite_height(int sprite_height, int sprite_width, int x, int start_x)
{
	int					start_y;
	int					end_y;
	int					i;
	int					texture_x;
	int					texture_y;

	start_y = (md.height / 2) - (sprite_height / 2);
	end_y = (md.height / 2) + (sprite_height / 2);
	if (start_y < 0)
		start_y = 0;
	if (end_y > md.height)
		end_y = md.height;
	i = start_y;
	texture_x = get_sp_tex_x(x - start_x, sprite_width);
	while (i < end_y)
	{
		texture_y = get_sp_tex_y(i - start_y, sprite_height);
		if (get_sp_texture(texture_x, texture_y) != 0)
			game.img_3d.data[i * md.width + x] = get_sp_texture(texture_x, texture_y);
		i++;
	}
}

void					draw_3d_sprite(int sprite_height, t_sprite sprite)
{
	int					start_x;
	int					end_x;
	int					i;
	int					sprite_width;
	double				sprite_angle;

	sprite_angle = atan2(sprite.pos.y - player.y, sprite.pos.x - player.x) - player.rot_angle;
	sprite_width = sprite_height;
	start_x = (md.width / 2) + (tan(sprite_angle) * g_dist_from_player);
	end_x = start_x + sprite_width;
	if (start_x < 0)
		start_x = 0;
	if (end_x > md.width)
		end_x = md.width;
	i = start_x;
	while (i < end_x)
	{
		draw_sprite_height(sprite_height, sprite_width, i, start_x);
		i++;
	}
}

void					calc_sprite(t_sprite *visible_sprite, int visible_sp_num)
{
	t_sprite			sprite;
	int					sprite_height;
	int					i;

	i = 0;
	while (i < visible_sp_num)
	{
		sprite = visible_sprite[i];
		sprite_height = (g_tile_size / sprite.distance) * g_dist_from_player;
		draw_3d_sprite(sprite_height, sprite);
		i++;
	}
}