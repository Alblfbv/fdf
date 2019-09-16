/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:22:04 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/16 16:46:20 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void	display_tabs(t_fdf *fdf)
{
	int		i = -1;
	/*
	ft_printf("----- tab 3d --------");
	while (++i < fdf->nb_vertices)
	{
		ft_printf("--%d--\n", i);
		ft_printf("x = %lf | y = %lf | z = %lf\n", fdf->vtcs_ref[i].x, fdf->vtcs_ref[i].y, fdf->vtcs_ref[i].z);
	}
	*/
	i = -1;
	ft_printf("-----tab edges-----\n");
	while (++i < fdf->nb_edges)
	{
		ft_printf("--- %d ---\n", i);
		ft_printf("vtc1 = %d | vtc2 = %d\n", fdf->edges[i].vtx_1, fdf->edges[i].vtx_2);
	}
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
//	if (!ret)
//		fdf_main_loop(&fdf);
	if (!ret)
		display_tabs(&fdf);
	free_fdf(&fdf);
	return (ret);
}
