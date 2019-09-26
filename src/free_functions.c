/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:32:10 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 16:33:50 by rkirszba         ###   ########.fr       */
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
	if (fdf->mlx_state == 5)
		mlx_destroy_image(fdf->mlx.ptrs.mlx_ptr, fdf->mlx.bg_img_bot.img_ptr);
	if (fdf->mlx_state >= 4)
		mlx_destroy_image(fdf->mlx.ptrs.mlx_ptr, fdf->mlx.bg_img_top.img_ptr);
	if (fdf->mlx_state >= 3)
		mlx_destroy_image(fdf->mlx.ptrs.mlx_ptr, fdf->mlx.img.img_ptr);
	if (fdf->mlx_state >= 2)
		mlx_destroy_window(fdf->mlx.ptrs.mlx_ptr, fdf->mlx.ptrs.win_ptr);
	ft_memdel((void**)&(fdf->edges));
	ft_memdel((void**)&(fdf->vtcs_3d));
	ft_memdel((void**)&(fdf->vtcs_2d));
}
