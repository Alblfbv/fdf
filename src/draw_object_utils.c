/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:00:06 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/26 19:19:11 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		give_interval(t_fdf *fdf, double z)
{
	int	i;

	i = -1;
	while (++i < NB_COLORS)
		if (z < fdf->color_tabs[fdf->mods.color_set][i].altitude)
			return (i);
	return (NB_COLORS);
}

void	swap_points(t_point_alt *p1, t_point_alt *p2)
{
	t_point_alt	swap;

	swap = *p1;
	*p1 = *p2;
	*p2 = swap;
}

void	compute_intermediate(t_fdf *fdf, t_point_alt *start,\
	t_point_alt *end, t_point_alt *tmp)
{
	t_color_alt	*tab;
	double		percentage;

	tab = fdf->color_tabs[fdf->mods.color_set];
	tmp->z = tab[start->interval].altitude;
	tmp->point.color = tab[start->interval].color;
	percentage = ft_percentage((tmp->z - start->z), (end->z - start->z));
	tmp->point.x =\
		start->point.x + percentage * (end->point.x - start->point.x);
	tmp->point.y =\
		start->point.y + percentage * (end->point.y - start->point.y);
}

int		compute_color(t_fdf *fdf, t_point_alt *point, int endian)
{
	t_color_alt	*tab;
	double		percentage;
	int			color1;
	int			color2;

	tab = fdf->color_tabs[fdf->mods.color_set];
	if (point->interval == 0)
		return (tab[0].color);
	if (point->interval == 5)
		return (tab[NB_COLORS - 1].color);
	percentage = ft_percentage(point->z - tab[point->interval - 1].altitude,\
		tab[point->interval].altitude - tab[point->interval - 1].altitude);
	color1 = tab[point->interval - 1].color;
	color2 = tab[point->interval].color;
	if (endian == LITTLE)
		return (l_mlx_compute_color_little(color1, color2, percentage));
	else
		return (l_mlx_compute_color_big(color1, color2, percentage));
}
