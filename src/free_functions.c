/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:32:10 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/16 16:45:17 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_list(t_lines *lines)
{
	t_lines	*tmp;

	while (lines)
	{
		tmp = lines;
		lines = lines->next;
		ft_free_split(tmp->split);
		free(tmp);
	}
}
		
void	free_fdf(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->mlx.img_ptr);
	mlx_destroy_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
//	voir s il y a un mlx quit
	ft_memdel((void**)&(fdf->edges));
	ft_memdel((void**)&(fdf->vtcs_ref));
	ft_memdel((void**)&(fdf->vtcs_3d));
	ft_memdel((void**)&(fdf->vtcs_2d));
}
