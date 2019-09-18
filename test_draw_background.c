/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:54:17 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/18 20:04:52 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#define WIN_WDTH 2560
#define WIN_HGHT 1440
#define COLOR_BG 0x1375FF
#define COLOR_WR 0xFFFFFF
#define X_STR 10
#define Y_STR 25
#define Y_OFFSET 40

//compiler command : gccflags -g -I /usr/local/include -I libft/includes -I libmlx/includes test_draw_background.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

void	draw_background(void *mlx_ptr, void *win_ptr)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HGHT)
	{
		x = -1;
		while (++x < WIN_WDTH)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, COLOR_BG);
	}
	x = X_STR;
	y = Y_STR;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "zoom = + or -");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "X-axis rotation = 7 or 9");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "Y-axis rotation = 4 or 6");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "Z-axis rotation = 1 or 3");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "X-axis move = q or w");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "Y-axis move = a or s");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "Z-axis move = z or x");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "altitude change = 2 or 8");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "isometric proj = !");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "other proj = @");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "antialiasing mode on / off = #");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "reset = del");
	y += Y_OFFSET;
	mlx_string_put(mlx_ptr, win_ptr, x, y, COLOR_WR, "quit = esc");
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WDTH, WIN_HGHT, "first try");
	draw_background(mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
