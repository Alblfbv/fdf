/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:13:28 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/14 19:55:50 by rkirszba         ###   ########.fr       */
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

# define SCREEN_WIDTH 0
# define SCREEN_HEIGHT 0
# define START_X 0
# define START_Y 0
# define TRANS_DELTA 1
# define ROT_DELTA (M_PI / 36)
# define SCALE_DELTA (10 / 100)
# define ALTITUDE_DELTA (10 / 100)
# define DEEP_BLUE 0x0
# define LIGHT_BLUE 0x0
# define GREEN 0x0
# define BROWN 0x0
# define WHITE 0x0
# define X_ROT_L 7
# define X_ROT_R 9
# define Y_ROT_L 4
# define Y_ROT_R 6
# define Z_ROT_L 1
# define Z_ROT_R 3
# define SCALE_P +
# define SCALE_M -
# define ISO !
# define OTHER @
# define RESET del
# define ESCAPE esc

typedef enum	e_projection
{
	iso,
	other,
}				t_projection;

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

typedef struct	s_modifiers
{
	int				trans_x;
	int				trans_y;
	int				trans_z;
	int				rot_x;
	int				rot_y;
	int				rot_z;
	double			scale_coef;
	double			altitude_mod;
	t_projection	proj;
}				t_modifiers;

typedef struct	s_matrices
{
	double	rot_mtx[4][4];
	double	scale_mtx[4][4];
	double	trans_mtx[4][4];
	double	proj_mtx[4][4];
	double	tmp_mtx[4][4];
}				t_matrices;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_buf;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}				t_mlx;

typedef struct	s_fdf
{
	int			nb_cols;
	int			nb_rows;
	int			nb_edges;
	int			base_scale;
	t_mlx		mlx;
	t_edge		*edges;
	t_vertex	*vtcs_3d;
	t_vertex	*vtcs_2d;
	t_modifiers	mods;
	t_matrices	mtx;
}				t_fdf;

#endif
