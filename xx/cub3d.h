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
	int					width;
	int					height;
	int					size_l;
	int					endian;
	int					bpp;
}						t_img;

typedef struct			s_game
{
	void				*mlx;
	t_img				img_2d;
	t_img				img_3d;
	void				*win;
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

typedef struct			s_direction
{
	void				*north;
	void				*south;
	void				*west;
	void				*east;
	int					no_w;
	int					no_h;
	int					so_w;
	int					so_h;
	int					ea_w;
	int					ea_h;
	int					we_w;
	int					we_h;
	int					*no_data;
	int					*so_data;
	int					*ea_data;
	int					*we_data;
	int					no_bpp;
	int					so_bpp;
	int					ea_bpp;
	int					we_bpp;
	int					no_endian;
	int					so_endian;
	int					ea_endian;
	int					we_endian;
	int					no_size_l;
	int					so_size_l;
	int					we_size_l;
	int					ea_size_l;
	int					check_no;
	int					check_so;
	int					check_ea;
	int					check_we;
}						t_direction;

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

typedef struct			s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct			s_ray
{
	double				dist;
	double				angle;
	t_point				hit_point;
}						t_ray;

typedef struct			s_key
{
	int					w_key;
	int					s_key;
	int					a_key;
	int					d_key;
	int					left_key;
	int					right_key;
}						t_key;

t_key					g_keys;
t_ray					*g_rays;
t_player				g_player;
t_direction				g_dir;
t_map_data				g_md;
t_game					g_game;
int						g_idx_width;
int						g_idx_height;
int						g_tile_size;
double					g_fov_angle;
int						g_num_rays;

//parse_cub.c
int						parse_cub(int fd);
int						data_setting(char *line);
int						data_check();
int						parse_data(int fd);
int						move_to_map(int fd, t_list **map_list);
//parse_map.c
char					**fill_map_data(t_list *map_list);
void					parse_map(int fd, t_list **map_list);
int						get_map_height(t_list *map_list);
int						get_map_width(t_list *map_list);
//map_utils.c
int						map_valid_check(char **map);
void					copy_map_data(char **map, t_list *map_list);
//map_valid_test.c
int						map_valid_test(char **map, int i, int j);
int						down_test(char **map, int i, int j);
int						left_test(char **map, int i, int j);
int						up_test(char **map, int i, int j);
int						right_test(char **map, int i, int j);
//parse_utils.c
int						count_splits(char **splits);
int						set_base_data(char **splits);
int						make_color(char *splits, t_color **color);
void					free_arrs(char **splits);
//save_utils.c
int						save_r(char **splits);
int						save_texture(char **splits);
int						save_color(char **splits);
//cub_setting.c
int						texture_setting();
int						cub_setting();
int						ray_setting();
void					player_setting();
//player_utils.c
void					set_angle(char direction);
void					player_init(int height, int width);
int						defence_seg_x(double angle);
int						defence_seg_y(double angle);
void					update(void);
//key_press.c
int						key_release(int keycode);
int						key_press(int keycode);
void					check_key(int keycode);
void					init_keys();
//utils1.c
int						has_wall_at(double x, double y);
int						calc_idx(double x, double y);
void					img_reset_2d();
void					img_reset_3d();
//cub_start.c
int						main_loop(void);
void					render();
//ray_cast.c
void					ray_cast_2d();
//draw.c
void					draw_lines();
void					draw_rectangles();
void					draw_player();
void					draw_line(double x1, double y1, double x2, double y2);
void					draw_rectangle(int row, int col);
#endif