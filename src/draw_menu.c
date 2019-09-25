/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:32:20 by allefebv          #+#    #+#             */
/*   Updated: 2019/09/25 15:04:36 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void menu_top_left(t_mlx *mlx)
{
	//OBJ MOVEMENTS
 	ROTATE
	TRANSLATE
	ALTITUDE
}

static void menu_top_right(t_mlx *mlx)
{
	//CAMERA MOVEMENTS
	SCALE
	MOVE
}

static void	menu_bot_right(t_mlx *mlx)
{
	//OPTIONS CHANGES
	PROJ_MODE
	ANTIALIASING
	COLORS
}

static void menu_bot_left(t_mlx *mlx)
{
	//OTHERS
	RESET
}

static void

void	draw_menu(t_mlx *mlx)
{
	int	x;
	int	y;

	x = X_STR;
	y = Y_STR;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "zoom = + or -");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "X-axis rotation = 7 or 9");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "Y-axis rotation = 4 or 6");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "Z-axis rotation = 1 or 3");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "X-axis move = q or w");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "Y-axis move = a or s");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "Z-axis move = z or x");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "altitude change = 2 or 8");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "isometric proj = !");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "cavalier proj = @");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "antialiasing mode on / off = $");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "reset = del");
	y += Y_OFFSET;
	mlx_string_put(mlx->ptrs.mlx_ptr, mlx->ptrs.win_ptr, x, y, COLOR_WR, "quit = esc");
}
