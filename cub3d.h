#ifndef CUB3D_H
# define CUB3D_H
# define ERROR					-1
# define SUCCESS				1
# define PI						3.1415926536
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_release	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_LEFT				123
# define KEY_RIGHT				124
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
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
	double				x;
	double				y;
	int					is_wall;
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
t_ray					*g_rays;
int						g_idx_width;
int						g_idx_height;
int						g_map_width;
int						g_map_height;
int						g_tile_size;
double					g_fov_angle;
int						g_num_rays;
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
int						main_loop();
//utils1.c
double					get_degree(int degree);
int						has_wall_at(double x, double y);
int						to_coord(double x, double y);
double					get_distance(int x1, int y1, int x2, int y2);
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
//ray_cast.c
void					ray_cast(int col_id, double angle);
void					vertical_wall_check(double angle, t_point *vert_wall);
void					horizontal_wall_check(double angle, t_point *horz_wall);
//ray_cast_util.c
void					get_next_horz_touch(t_point touch, t_point **horz_wall, t_point step, int angle_side_up);
void					get_next_vert_touch(t_point touch, t_point **vert_wall, t_point step, int angle_side_left );
void					get_ray_data(double dist, int col_id, t_point wall_point);
#endif