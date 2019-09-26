/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:59:32 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 18:07:24 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

# include <math.h>
# include "mlx.h"
# include "libft.h"

# define X 0
# define Y 1
# define LITTLE 0
# define BIG 1
# define START 0
# define END 1

typedef struct	s_point
{
	double	x;
	double	y;
	int		color;
	int		endian;
}				t_point;

typedef struct	s_plan
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}				t_plan;

typedef struct	s_ptrs
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ptrs;

typedef struct	s_img
{
	void	*img_ptr;
	char	*buf;
	int		bits_per_pixel;
	int		size_line;
	int		size_buf;
	t_plan	plan;
	int		endian;
}				t_img;

typedef struct	s_subcolors
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	alpha;
}				t_subcolors;

typedef struct	s_draw_line
{
	int		steep;
	double	y_intrsct;
	double	gradient;
	int		x_pxl_start;
	int		x_pxl_end;
}				t_draw_line;

void			l_mlx_draw_line_xiaolin(t_img *img, t_point start, t_point end);
void			l_mlx_draw_line_bresenham(t_img *img, t_point start,\
	t_point end);
void			l_mlx_line_win_bresenham(t_ptrs *ptrs, t_point start,\
	t_point end);
void			l_mlx_write_pixel(t_img *img, t_point *point);
void			l_mlx_write_pixel_pct(t_img *img, t_point *point,\
	double percentage);
int				l_mlx_actualize_points(t_point *start, t_point *end,\
	t_plan *plan);
int				check_projection(t_point *var_point, t_point *ref_point,\
	t_plan *plan);
int				l_mlx_is_x_on_plan(double x, t_plan *plan);
int				l_mlx_is_y_on_plan(double y, t_plan *plan);
int				l_mlx_is_on_plan(t_point *point, t_plan *plan);
int				l_mlx_compute_color(t_point *start, t_point *end,\
	t_point *curr);
int				l_mlx_sub_to_color(t_subcolors sub, int endian);
unsigned char	l_mlx_compute_sub_color(unsigned char sub1, unsigned char sub2,\
	double percentage);
int				l_mlx_compute_color_big(int color1, int color2,\
	double percentage);
int				l_mlx_compute_color_little(int color1, int color2,\
	double percentage);
double			l_mlx_compute_gradient(t_point *p1, t_point *p2);
t_point			l_mlx_x_projection(t_point *var_point, double gradient,\
	int value);
t_point			l_mlx_y_projection(t_point *var_point, double gradient,\
	int value);
t_point			l_mlx_projection(t_point *var_point, double gradient,\
	int axis, int value);

#endif
