/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <rkirszba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:51:58 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/16 16:31:48 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	append_line(t_lines **lines, char **split)
{
	t_lines	*line;
	t_lines	*current;

	if (!(line = (t_lines*)malloc(sizeof(t_lines))))
	{
		ft_free_split(split);
		return (print_sys_error(errno));
	}
	line->split = split;
	line->next = NULL;
	if (!*lines)
	{
		*lines = line;
		return (0);
	}
	current = *lines;
	while (current->next)
		current = current->next;
	current->next = line;
	return (0);
}

static int	check_line(t_fdf *fdf, t_lines **lines, char *line)
{
	char	**split;
	int		nb_cols;

	if (!(split = ft_strsplit(line, ' ')))
		return (print_sys_error(errno));
	nb_cols = -1;
	while (split[++nb_cols])
		if (!ft_is_int(split[nb_cols]))
		{
			ft_free_split(split);
			return (print_input_error(1));
		}
	if (!nb_cols || (fdf->nb_cols && nb_cols != fdf->nb_cols))
	{	
		ft_free_split(split);
		print_input_error(2);
	}
	if (!fdf->nb_cols)
		fdf->nb_cols = nb_cols;
	return (append_line(lines, split));
}

static int copy_list_to_tab(t_fdf *fdf, t_lines *lines)
{
	int	index;
	int	x;
	int	y;

	fdf->nb_vertices = fdf->nb_cols * fdf->nb_rows;
	if (!(fdf->vtcs_ref = (t_vertex*)malloc(sizeof(t_vertex) * fdf->nb_vertices)))
		return (print_sys_error(errno));
	index = 0;
	y = -1;
	while (++y < fdf->nb_rows)
	{
		x = -1;
		while (++x < fdf->nb_cols)
		{
			fdf->vtcs_ref[index].x = (double)x;
			fdf->vtcs_ref[index].y = (double)y;
			fdf->vtcs_ref[index].z = (double)ft_atoi(lines->split[x]);
			index++;
		}
		lines = lines->next;
	}
	return (0);
}

int			parse_map(t_fdf *fdf, int fd)
{
	char	*line;
	char	*str;
	t_lines	*lines;
	int		ret;

	line = NULL;
	lines = NULL;
	str = NULL;
	while ((ret = get_next_line2(fd, &line, &str)) > 0)
	{
		if (ret == -1 || (ret = check_line(fdf, &lines, line)))
			break ;
		ft_strdel(&line);
		(fdf->nb_rows)++;
	}
	ft_strdel(&line);
	ft_strdel(&str);
	if (ret)
	{
		free_list(lines);
		return (ret == -1 ? print_sys_error(errno) : 1);
	}
	ret = copy_list_to_tab(fdf, lines);
	free_list(lines);	
	return (ret);
}