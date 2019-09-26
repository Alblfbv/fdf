/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:32:20 by allefebv          #+#    #+#             */
/*   Updated: 2019/09/26 16:29:44 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_putstr(t_ptrs *ptrs, t_point *point, char *str, int spacing)
{
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, point->x, point->y, COLOR_WR,\
		str);
	point->y += spacing;
}

static void	menu_cam_opt(t_ptrs *ptrs, t_point *point)
{
	fdf_putstr(ptrs, point, "CAMERA COMMANDS", LINE_SPACE);
	fdf_putstr(ptrs, point, "-----------------------------", TITLE_SPACE);
	fdf_putstr(ptrs, point, "ZOOM ---", LINE_SPACE);
	fdf_putstr(ptrs, point, "-> + / -", TITLE_SPACE);
	fdf_putstr(ptrs, point, "CAMERA MOVE ---", LINE_SPACE);
	fdf_putstr(ptrs, point, "down -> v", LINE_SPACE);
	fdf_putstr(ptrs, point, "up -> ^", LINE_SPACE);
	fdf_putstr(ptrs, point, "left -> <", LINE_SPACE);
	fdf_putstr(ptrs, point, "right -> >", BLOCK_SPACE);
	fdf_putstr(ptrs, point, "OPTIONS COMMANDS", LINE_SPACE);
	fdf_putstr(ptrs, point, "-----------------------------", TITLE_SPACE);
	fdf_putstr(ptrs, point, "PROJECTION MODES ---", LINE_SPACE);
	fdf_putstr(ptrs, point, "isometric -> !", LINE_SPACE);
	fdf_putstr(ptrs, point, "cavalier-> @", LINE_SPACE);
	fdf_putstr(ptrs, point, "cabinet-> #", TITLE_SPACE);
	fdf_putstr(ptrs, point, "ANTIALIASING ---", LINE_SPACE);
	fdf_putstr(ptrs, point, "on / off -> $", BLOCK_SPACE);
}

static void	menu_col_obj(t_ptrs *ptrs, t_point *point)
{
	fdf_putstr(ptrs, point, "COLOR MODIFICATION COMMANDS", LINE_SPACE);
	fdf_putstr(ptrs, point, "-----------------------------", TITLE_SPACE);
	fdf_putstr(ptrs, point, "UNICOLOR MODE ---  -> [", LINE_SPACE);
	fdf_putstr(ptrs, point, "red ++ -> r", LINE_SPACE);
	fdf_putstr(ptrs, point, "red -- -> e", LINE_SPACE);
	fdf_putstr(ptrs, point, "green ++ -> g", LINE_SPACE);
	fdf_putstr(ptrs, point, "green -- -> f", LINE_SPACE);
	fdf_putstr(ptrs, point, "blue ++ -> b", LINE_SPACE);
	fdf_putstr(ptrs, point, "blue -- -> v", TITLE_SPACE);
	fdf_putstr(ptrs, point, "POLYCOLORS --- -> ]", LINE_SPACE);
	fdf_putstr(ptrs, point, "cycle through -> \\", BLOCK_SPACE);
	fdf_putstr(ptrs, point, "OBJECT MODIFICATIONS COMMANDS", LINE_SPACE);
	fdf_putstr(ptrs, point, "-----------------------------", TITLE_SPACE);
	fdf_putstr(ptrs, point, "ROTATIONS ---", LINE_SPACE);
	fdf_putstr(ptrs, point, "X-axis -> 7 / 9", LINE_SPACE);
	fdf_putstr(ptrs, point, "Y-axis -> 4 / 6", LINE_SPACE);
	fdf_putstr(ptrs, point, "Z-axis -> 1 / 3", TITLE_SPACE);
	fdf_putstr(ptrs, point, "TRANSLATIONS ---", LINE_SPACE);
	fdf_putstr(ptrs, point, "X-axis -> q / w", LINE_SPACE);
	fdf_putstr(ptrs, point, "Y-axis -> a / s", LINE_SPACE);
	fdf_putstr(ptrs, point, "Z-axis -> z / x", TITLE_SPACE);
	fdf_putstr(ptrs, point, "ALTITUDE ---", LINE_SPACE);
	fdf_putstr(ptrs, point, "-> 2 / 8", BLOCK_SPACE);
}

void		draw_menu(t_ptrs *ptrs)
{
	t_point point;

	point.x = X_MARGIN;
	point.y = START_Y_IMG + Y_MARGIN;
	fdf_putstr(ptrs, &point, "BASIC MENU COMMANDS", LINE_SPACE);
	fdf_putstr(ptrs, &point, "-----------------------------", TITLE_SPACE);
	fdf_putstr(ptrs, &point, "reset -> del", LINE_SPACE);
	fdf_putstr(ptrs, &point, "quit -> esc", BLOCK_SPACE);
	menu_col_obj(ptrs, &point);
	menu_cam_opt(ptrs, &point);
}
