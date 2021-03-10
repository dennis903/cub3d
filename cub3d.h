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
# define KEY_TAB				48
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "mlx_dylib/mlx.h"


typedef struct			s_point
{
	double				x;
	double				y;
	int					is_wall;
}						t_point;

typedef struct			s_sprite_utils
{
	int					start_x;
	int					end_x;
	int					start_y;
	int					end_y;
}						t_sprite_utils;

typedef struct			s_img
{
	void				*img;
	int					width;
	int					height;
	int					*data;
	int					endian;
	int					bpp;
	int					size_l;
}						t_img;

typedef struct			s_3d_data
{
	double				actual_wall_height;
	double				dist_to_wall;
	double				proj_wall_height;
	double				dist_from_player;
}						t_3d_data;

typedef struct			s_direction
{
	void				*north;
	void				*south;
	void				*west;
	void				*east;
	void				*sprite;
	int					no_w;
	int					no_h;
	int					so_w;
	int					so_h;
	int					ea_w;
	int					ea_h;
	int					we_w;
	int					we_h;
	int					sp_w;
	int					sp_h;
	int					*no_data;
	int					*so_data;
	int					*ea_data;
	int					*we_data;
	int					*sp_data;
	int					no_bpp;
	int					so_bpp;
	int					ea_bpp;
	int					we_bpp;
	int					sp_bpp;
	int					no_endian;
	int					so_endian;
	int					ea_endian;
	int					we_endian;
	int					sp_endian;
	int					no_size_l;
	int					so_size_l;
	int					we_size_l;
	int					ea_size_l;
	int					sp_size_l;
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

typedef struct			s_sprite
{
	t_point				pos;
	double				distance;
	double				angle;
	char				visible;
}						t_sprite;

typedef struct			s_key
{
	int					w_key;
	int					s_key;
	int					a_key;
	int					d_key;
	int					left_key;
	int					right_key;
	int					tab_key;
}						t_key;

typedef struct			s_game
{
	void				*mlx;
	void				*win;
	t_img				img_2d;
	t_img				img_3d;
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

typedef struct			s_ray
{
	double				ray_angle;
	double				distance;
	t_point				hit_point;
	char				side;
}						t_ray;

t_game					game;
t_map_data				md;
t_player				player;
t_key					g_keys;
t_ray					*g_rays;
t_direction				g_dir;
t_3d_data				g_3d;
t_sprite				*g_sprites;

char					g_sprite_num;
int						g_idx_width;
int						g_idx_height;
int						g_tile_size;
int						h_tile_size;
double					g_fov_angle;
int						g_num_rays;
double					g_dist_from_player;
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
void					set_angle(char direction);
void					player_init(int height, int width);
int						defence_seg_y(double angle);
int						defence_seg_x(double angle);
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
int						texture_setting();
int						cub_setting();
int						sprite_setting();
void					player_setting();
void					ray_setting();
//key_press.c
int						key_release(int keycode);
int						key_press(int keycode);
int						key_exit();
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
void					raycast_3d();
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
void					get_next_horz_touch(t_point intercept, t_point **horz_wall, t_point step, int angle_side_up);
void					get_next_vert_touch(t_point intercept, t_point **vert_wall, t_point step, int angle_side_left );
void					get_ray_data(double dist, int col_id, t_point wall_point);
//ray_cast_3d.c
void					draw_ceiling();
void					draw_floor();
void					draw_wall();
void					draw_3d_wall(double x, int wall_strip_height, t_ray ray);
//texture_admin.c
unsigned int			fill_color(t_color *color);
void					check_direction(t_ray ray);
void					init_direction();
//texture_utils.c
void					is_dir_up(int left, t_ray ray);
void					is_dir_down(int left, t_ray ray);
int						get_texture_x(t_ray ray);
int						get_texture_y(int screen_y, int wall_height);
int						get_texture_color(int x, int y);
//utils2.c
int						calc_idx(int x, int y);
int						count_sprite();
t_ray					rot_angle_ray_cast(double angle);
double					fix_angle(double angle);
//reset_img.c
void					image_reset_2d();
void					image_reset_3d();
//sprite_util.c
void					sprite_pos_set();
void					draw_2d_sprite(int y, int x, int color);
void					draw_3d_sprite(int sprite_height, t_sprite sprite);
void					draw_sprite_height(int sprite_height, int sprite_width, int x, t_sprite_utils sp_utils);
void					sort_sprite(t_sprite *visible_sprite, int visible_sp_num);
//sprite.c
void					sprite_2d();
void					sprite_3d();
void					calc_sprite(t_sprite *visible_sprite, int visible_sp_num);
//make_bmp.c
int						make_bmp();
void					set_bmp_header(unsigned char *header);
//bmp_utils.c
int						calc_bmp_size();
//sprite_textures.c
int						get_sp_tex_x(int current_x, int sprite_width);
int						get_sp_tex_y(int current_y, int sprite_height);
int						get_sp_texture(int x, int y);
#endif