/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:32:20 by allefebv          #+#    #+#             */
/*   Updated: 2019/09/25 16:45:33 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	menu_object2(t_ptrs *ptrs, int x, int *y)
{
 	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"TRANSLATIONS ---");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"X-axis -> q / w");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"Y-axis -> a / s");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"Z-axis -> z / x");
	(*y) += Y_TITLE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"ALTITUDE ---");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"-> 2 / 8");
	(*y) += Y_BLOCK;
}

static void	menu_object(t_ptrs *ptrs, int x, int *y)
{
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"OBJECT MODIFICATIONS");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"------------------------");
	(*y) += Y_TITLE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"ROTATIONS ---");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"X-axis -> 7 / 9");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"Y-axis -> 4 / 6");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"Z-axis -> 1 / 3");
	(*y) += Y_TITLE;
	menu_object2(ptrs, x, y);
}

static void	menu_camera(t_ptrs *ptrs, int x, int *y)
{
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"CAMERA MODIFICATIONS");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"------------------------");
	(*y) += Y_TITLE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR, "ZOOM ---");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR, "-> + / -");
	(*y) += Y_TITLE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"CAMERA MOVE ---");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR, "down -> v");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR, "up -> ^");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR, "left -> <");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR, "right -> >");
	(*y) += Y_BLOCK;
}

static void	menu_options(t_ptrs *ptrs, int x, int *y)
{
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"OPTIONS MODIFICATIONS");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"------------------------");
	(*y) += Y_TITLE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"PROJECTION MODES ---");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"isometric -> !");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"cavalier -> @");
	(*y) += Y_TITLE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"ANTIALIASING ---");
	(*y) += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, *y, COLOR_WR,\
		"on / off -> $");
	(*y) += Y_BLOCK;
}

void	draw_menu(t_ptrs *ptrs)
{
	int	y;
	int	x;

	y = START_Y_IMG + Y_MARGIN;
	x = X_MARGIN;
	menu_object(ptrs, x, &y);
	menu_camera(ptrs, x, &y);
	menu_options(ptrs, x, &y);
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, y, COLOR_WR,\
		"BASIC MENU MODIFICATIONS");
	y += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, y, COLOR_WR,\
		"------------------------");
	y += Y_TITLE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, y, COLOR_WR,\
		"reset -> del");
	y += Y_LINE;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, x, y, COLOR_WR, "quit -> esc");
}
