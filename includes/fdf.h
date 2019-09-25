/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:13:28 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/25 16:45:50 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "mlx.h"
# include "libft.h"
# include "libmlx.h"

# define WIN_WDTH 2560
# define WIN_HGHT 1400
# define START_X_IMG 0
# define START_Y_IMG 80
# define IMG_WDTH (WIN_WDTH - START_X_IMG)
# define IMG_HGHT (WIN_HGHT - (START_Y_IMG * 2))
# define X_SHIFT (0.1 * IMG_WDTH)
# define Y_SHIFT (0.17 * IMG_HGHT)
# define MOVE_DELTA 10
# define TRANS_DELTA 15
# define ROT_DELTA (M_PI / 36)
# define SCALE_DELTA 0.1
# define ALTITUDE_DELTA 0.1
# define NB_COLORS 5
# define DEEP_BLUE_INT 0x042295
# define DEEP_BLUE_ALT (-10)
# define LIGHT_BLUE_INT 0x45B5FF
# define LIGHT_BLUE_ALT (-5)
# define GREEN_INT 0x00FF00
# define GREEN_ALT 1
# define BROWN_INT 0xAD6924
# define BROWN_ALT 10
# define WHITE_INT 0xFFFFFFFF
# define WHITE_ALT 20
# define MOVE_L 123 // LEFT_ARROW
# define MOVE_R 124 // RIGHT_ARROW
# define MOVE_U 126 // UP_ARROW
# define MOVE_D 125 // DOWN_ARROW
# define X_ROT_L 89 //7
# define X_ROT_R 92 //9
# define Y_ROT_L 86 //4
# define Y_ROT_R 88 //6
# define Z_ROT_L 83 //1
# define Z_ROT_R 85 //3
# define X_TRANS_L 12 //q
# define X_TRANS_R 13 //w
# define Y_TRANS_L 0 //a
# define Y_TRANS_R 1 //s
# define Z_TRANS_L 6 //z
# define Z_TRANS_R 7 //x
# define SCALE_M 78 //-
# define SCALE_P 69 //+
# define ALT_M 84 //2
# define ALT_P 91 //8
# define ISO 18 //!
# define CABINET 19 // @
# define ALIASING 21 // 4
# define RESET 51 //del
# define QUIT 53 //esc
# define EVENTS_NB 25 //nombre a actualiser
# define KEY_PRESS 2
# define RED_BUTTON 17
# define COLOR_BG 0x000F28
# define COLOR_WR 0xFFFFFF
# define X_MARGIN 10
# define Y_MARGIN 200
# define Y_BLOCK 70
# define Y_TITLE 30
# define Y_LINE 15


typedef enum	e_projection
{
	iso,
	cabinet,
}				t_projection;

typedef enum	e_draw_mode
{
	bresenham,
	xiaolin,
}				t_draw_mode;

typedef struct	s_vertex
{
	double	x;
	double	y;
	double 	z;
}				t_vertex;

typedef struct	s_edge
{
	int	vtx_1;
	int	vtx_2;
}				t_edge;

typedef struct	s_point_alt
{
	t_point	point;
	double	z;
	int		interval;
}				t_point_alt;

typedef struct	s_color_alt
{
	int		color;
	double	altitude;
}				t_color_alt;

typedef struct	s_modifiers
{
	double			alt_mod;
	double			scale_coef;
	int				trans_x;
	int				trans_y;
	int				trans_z;
	int				rot_x;
	int				rot_y;
	int				rot_z;
	t_projection	proj;
	int				move_x;
	int				move_y;
	t_draw_mode		draw_mode;
}				t_modifiers;

typedef struct	s_matrices
{
	double	alt_mtx[4][4];
	double	scale_mtx[4][4];
	double	trans_mtx[4][4];
	double	rot_x_mtx[4][4];
	double	rot_y_mtx[4][4];
	double	rot_z_mtx[4][4];
	double	proj_mtx[4][4];
	double	move_mtx[4][4];
	double	tmp_mtx[4][4];
}				t_matrices;

typedef struct	s_mlx
{
	t_ptrs	ptrs;
	t_img	img;
}				t_mlx;

typedef struct	s_fdf
{
	int			nb_cols;
	int			nb_rows;
	int			nb_vertices;
	int			nb_edges;
	int			base_scale;
	int			shift_x;
	int			shift_y;
	int			mlx_off;
	t_mlx		mlx;
	t_edge		*edges;
	t_vertex	*vtcs_3d;
	t_vertex	*vtcs_2d;
	t_modifiers	mods;
	t_matrices	mtx;
}				t_fdf;

typedef struct	s_lines
{
	char			**split;
	struct s_lines	*next;
}				t_lines;

typedef struct	s_event
{
	int	keycode;
	int (*function)(int, t_fdf*);
}				t_event;

/*
** map parsing
*/

int			parse_map(t_fdf *fdf, int fd);

/*
** main structure init
*/

int			init_fdf(t_fdf *fdf);

/*
** projection functions
*/

void		reinit_matrices(t_fdf *fdf);
void		reinit_alt_matrix(t_fdf *fdf);
void		reinit_move_matrix(t_fdf *fdf);
void		reinit_proj_matrix(t_fdf *fdf);
void		reinit_trans_matrix(t_fdf *fdf);
void		reinit_scale_matrix(t_fdf *fdf);
void		reinit_rot_x_matrix(t_fdf *fdf);
void		reinit_rot_y_matrix(t_fdf *fdf);
void		reinit_rot_z_matrix(t_fdf *fdf);
void		compute_tmp_matrix(t_fdf *fdf);
void		transform_coor(t_fdf *fdf);

/*
** drawing functions
*/

void		display_object_routine(t_fdf *fdf);
void		draw_object(t_fdf *fdf);
void		draw_menu(t_ptrs *ptrs);
void		swap_points(t_point_alt *p1, t_point_alt *p2);
int			give_interval(double z1);
t_color_alt	*tab_color_alt(void);
void		draw_line(t_fdf *fdf, t_point_alt *start, t_point_alt *end,\
			t_draw_mode draw_mode);

/*
** events handlers
*/

int			handle_key_events(int keycode, t_fdf *fdf);
int			handle_rot_events(int keycode, t_fdf *fdf);
int			handle_scale_events(int keycode, t_fdf *fdf);
int			handle_trans_events(int keycode, t_fdf *fdf);
int			handle_move_events(int keycode, t_fdf *fdf);
int			handle_proj_events(int keycode, t_fdf *fdf);
int			handle_alt_events(int keycode, t_fdf *fdf);
int			handle_draw_mode_event(int keycode, t_fdf *fdf);
int			handle_reset_event(int keycode, t_fdf *fdf);
int			handle_quit_event(int keycode, t_fdf *fdf);
int			handle_quit_event_mouse(t_fdf *fdf);

/*
** free functions
*/

void		free_fdf(t_fdf *fdf);
void		free_list(t_lines *lines);

/*
** error functions
*/

int			print_usage(void);
int			print_sys_error(int errnum);
int			print_input_error(int errnum);
int			print_mlx_error(int errnum);


#endif
