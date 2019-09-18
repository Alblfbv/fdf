/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:00:44 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/18 19:29:25 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

// compiler command : gccflags -g -I /usr/local/include -I libft/includes -I libmlx/includes test_events.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

typedef struct s_test
{
	int	x;
	int	y;
}				t_test;

int		handle_key_events(int keycode, t_test *test)
{
	(void)test;

	if (keycode == 53)
		exit(0);
	printf("keycode = %d\n", keycode);
	return (0);
}

int		handle_expose_event(t_test *test)
{
	(void)test;
	exit(0);
}

int		main(void)
{
	t_test	test;
	void	*mlx_ptr;
	void	*win_ptr;
	
	test.x = 1;
	test.y = 1;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "first try");
	mlx_hook(win_ptr, 2, 0, &handle_key_events, &test);
	mlx_hook(win_ptr, 17, 0, &handle_expose_event, &test);
//	mlx_key_hook(win_ptr, &handle_key_events, &test);
//	mlx_expose_hook(win_ptr, &handle_expose_event, &test);
	mlx_loop(mlx_ptr);
	return (0);
}
