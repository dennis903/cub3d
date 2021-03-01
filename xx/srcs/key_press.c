#include "../cub3d.h"

void				init_keys()
{
	g_keys.w_key = 0;
	g_keys.a_key = 0;
	g_keys.d_key = 0;
	g_keys.s_key = 0;
	g_keys.left_key = 0;
	g_keys.right_key = 0;
}

void				check_key(int keycode)
{
	if (keycode == KEY_W)
		g_keys.w_key = 1;
	else if (keycode == KEY_A)
		g_keys.a_key = 1;
	else if (keycode == KEY_S)
		g_keys.s_key = 1;
	else if (keycode == KEY_D)
		g_keys.d_key = 1;
	else if (keycode == KEY_LEFT)
		g_keys.left_key = 1;
	else if (keycode == KEY_RIGHT)
		g_keys.right_key = 1;
}

int					key_press(int keycode)
{
	init_keys();
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		g_player.walk_dir = 1;
	else if (keycode == KEY_S)
		g_player.walk_dir = -1;
	if (keycode == KEY_A)
		g_player.walk_dir = 1;
	else if (keycode == KEY_D)
		g_player.walk_dir = -1;
	if (keycode == KEY_LEFT)
		g_player.turn_dir = -1;
	else if (keycode == KEY_RIGHT)
		g_player.turn_dir = 1;
	check_key(keycode);
	return (0);
}

int					key_release(int keycode)
{
	if (keycode == KEY_W)
	{
		g_player.walk_dir = 0;
		g_keys.w_key = 0;
	}
	else if (keycode == KEY_S)
	{
		g_player.walk_dir = 0;
		g_keys.s_key = 0;
	}
	if (keycode == KEY_A)
	{
		g_player.walk_dir = 0;
		g_keys.a_key = 0;
	}
    else if (keycode == KEY_D)
	{
		g_player.walk_dir = 0;
		g_keys.d_key = 0;
	}
	if (keycode == KEY_LEFT)
	{
		g_player.turn_dir = 0;
		g_keys.left_key = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		g_player.turn_dir = 0;
		g_keys.right_key = 0;
	}
	return (0);
}