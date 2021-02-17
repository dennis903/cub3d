#ifndef CUB3D_H
# define CUB3D_H
# define ERROR					-1
# define SUCCESS				1
# define PI						3.1415926536
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_release	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					12
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define FOV_ANGLE				60
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "mlx_dylib/mlx.h"

typedef struct			s_img
{
	void				*img;
	int					*data;
	int					endian;
	int					bpp;
	int					size_l;
}						t_img;

typedef struct			s_player
{
	double				x;
	double				y;
	double				radius;
	double				turn_dir;
	double				walk_dir;
	double				rot_angle;
	double				move_speed;
	double				rotation_speed;
}						t_player;

typedef struct			s_key
{
	int					w_key;
	int					s_key;
	int					a_key;
	int					d_key;
	int					left_key;
	int					right_key;
}						t_key;

typedef struct			s_game
{
	void				*mlx;
	void				*win;
	t_img				img;
	char				**map;
}						t_game;

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct			s_map_data
{
	int					width;
	int					height;
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	char				*sprite;
	struct s_color		*f;
	struct s_color		*c;
}						t_map_data;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_ray
{
	double				ray_angle;
	double				distance;
	t_point				hit_point;
}						t_ray;

t_game					game;
t_map_data				md;
t_player				player;
t_key					g_keys;
t_ray					*rays;
int						g_idx_width;
int						g_idx_height;
int						g_tile_size;
//parse_cub.c
int						parse_cub(int fd);
//parse_utils.c
int						set_base_data(char **splits);
int						count_splits(char **splits);
int						make_color(char *splits, t_color **color);
void					free_arrs(char **splits);
//save.c
int						save_r(char **splits);
int						save_texture(char **splits);
int						save_color(char **splits);
//player_util.c
void					update(void);
//map_valid_test.c
int						map_valid_test(char **map, int i, int j);
//parse_map.c
void					parse_map(int fd, t_list **map_list);
char					**fill_map_data(t_list *map_list);
int						get_map_width(t_list *map_list);
int						get_map_height(t_list *map_list);
//map_utils.c
void					copy_map_data(char **map, t_list *map_list);
int						map_valid_check(char **map);
//cub_setting.c
int						cub_setting();
//key_press.c
int						key_release(int keycode);
int						key_press(int keycode);
//cub3d_start.c
int						main_loop(void);
//utils1.c
double					get_degree(int degree);
int						has_wall_at(double x, double y);
int						to_coord(double x, double y);
//render.c
void					render();
void					draw_2d_ray();
//image.c
//draw.c
void					draw_player();
void					draw_line(double x1, double y1, double x2, double y2, int color);
void					draw_lines();
void					draw_rectangles();
void					draw_rectangle(int row, int col);
//cub2d_utils.c
double					normalize_angle(double ray_angle);
#endif