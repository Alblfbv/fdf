/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <allefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:21:23 by allefebv          #+#    #+#             */
/*   Updated: 2019/09/26 19:21:59 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_set0_colors(t_fdf *fdf)
{
	fdf->color_tabs[0][0].color = SET0_COL0_INT;
	fdf->color_tabs[0][0].altitude = SET0_COL0_ALT;
	fdf->color_tabs[0][1].color = SET0_COL1_INT;
	fdf->color_tabs[0][1].altitude = SET0_COL1_ALT;
	fdf->color_tabs[0][2].color = SET0_COL2_INT;
	fdf->color_tabs[0][2].altitude = SET0_COL2_ALT;
	fdf->color_tabs[0][3].color = SET0_COL3_INT;
	fdf->color_tabs[0][3].altitude = SET0_COL3_ALT;
	fdf->color_tabs[0][4].color = SET0_COL4_INT;
	fdf->color_tabs[0][4].altitude = SET0_COL4_ALT;
}

static void	init_set1_colors(t_fdf *fdf)
{
	fdf->color_tabs[1][0].color = SET1_COL0_INT;
	fdf->color_tabs[1][0].altitude = SET1_COL0_ALT;
	fdf->color_tabs[1][1].color = SET1_COL1_INT;
	fdf->color_tabs[1][1].altitude = SET1_COL1_ALT;
	fdf->color_tabs[1][2].color = SET1_COL2_INT;
	fdf->color_tabs[1][2].altitude = SET1_COL2_ALT;
	fdf->color_tabs[1][3].color = SET1_COL3_INT;
	fdf->color_tabs[1][3].altitude = SET1_COL3_ALT;
	fdf->color_tabs[1][4].color = SET1_COL4_INT;
	fdf->color_tabs[1][4].altitude = SET1_COL4_ALT;
}

static void	init_set2_colors(t_fdf *fdf)
{
	fdf->color_tabs[2][0].color = SET2_COL0_INT;
	fdf->color_tabs[2][0].altitude = SET2_COL0_ALT;
	fdf->color_tabs[2][1].color = SET2_COL1_INT;
	fdf->color_tabs[2][1].altitude = SET2_COL1_ALT;
	fdf->color_tabs[2][2].color = SET2_COL2_INT;
	fdf->color_tabs[2][2].altitude = SET2_COL2_ALT;
	fdf->color_tabs[2][3].color = SET2_COL3_INT;
	fdf->color_tabs[2][3].altitude = SET2_COL3_ALT;
	fdf->color_tabs[2][4].color = SET2_COL4_INT;
	fdf->color_tabs[2][4].altitude = SET2_COL4_ALT;
}

void		init_tab_color(t_fdf *fdf)
{
	init_set0_colors(fdf);
	init_set1_colors(fdf);
	init_set2_colors(fdf);
}
