/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:59:32 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/09 19:06:01 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

# include <math.h>
# include "mlx.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

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
	int		height;
	int		width;
	int		endian;
}				t_img;

void	l_mlx_draw_line(t_ptrs *ptrs, t_img *img, t_point *points, int **colors);
int		l_mlx_bufpos(t_img *img, t_point *point); //return -1 si en dehors de l'image (si x < ou > width et y < ou > height)
int		l_mlx_compute_color(t_point *limits, t_point *pos, int **colors);
void	l_mlx_write_pixel(t_img *img, int index, int color);



#endif
