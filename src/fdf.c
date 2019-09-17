/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:22:04 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/17 18:40:55 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void	display_tabs(t_fdf *fdf)
{
	int		i = -1;
	ft_printf("----- tab 3d --------\n");
	while (++i < fdf->nb_vertices)
	{
		ft_printf("---%d---\n", i);
		ft_printf("x = %lf | y = %lf | z = %lf\n", fdf->vtcs_ref[i].x, fdf->vtcs_ref[i].y, fdf->vtcs_ref[i].z);
	}
	i = -1;
	ft_printf("-----tab edges-----\n");
	while (++i < fdf->nb_edges)
	{
		ft_printf("--- %d ---\n", i);
		ft_printf("vtc1 = %d | vtc2 = %d\n", fdf->edges[i].vtx_1, fdf->edges[i].vtx_2);
	}
}

void		display_object_routine(t_fdf *fdf)
{
	compute_matrices(fdf);
	transform_coor(fdf);
	draw_object(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, START_X_IMG,\
		START_Y_IMG);
	ft_bzero(&fdf->mlx.img.buf, sizeof(char) * fdf->mlx.img.size_buf);
}


int			handle_rot_events(int keycode, t_fdf *fdf)
{
}

int			handle_key_events(int keycode, t_fdf *fdf)
{
	static t_event	tab[EVENTS_NB] =  
	int				i;

	i = -1;
	while (++i < EVENTS_NB)
		if (tab[i].keycode == keycode)
			return (tab[i].function(keycode, fdf));
	return (0);
}

int			main(int ac, char **av)
{
	t_fdf	fdf;
	int		ret;
	int		fd;

	if (ac != 2)
		return (print_usage());
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (print_sys_error(errno));
	ft_bzero(&fdf, sizeof(t_fdf));
	ret = parse_map(&fdf, fd);
	if (!ret)
		ret = init_fdf(&fdf);
	if (!ret)
	{
		display_object_routine(fdf);
		if ((mlx_key_hook(fdf->mlx.win_ptr, &handle_key_events, fdf)))
			goto end ;
		if (mlx_loop(fdf->mlx.mlx_ptr))
			goto end ;
	}
//	if (!ret)
//		display_tabs(&fdf);
end:	
	free_fdf(&fdf);
	return (ret);
}
