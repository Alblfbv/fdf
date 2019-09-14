/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkirszba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:22:04 by rkirszba          #+#    #+#             */
/*   Updated: 2019/09/14 19:55:47 by rkirszba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		append_line(t_list **lines, char **split)
{
	t_list	*new;
	
	if (!(new = ft_lstnew(split, sizeof(split))))
	{
		ft_free_split(split) // fonction a ajouter de ma lib
		return (print_sys_error(errno));
	}
	ft_lst_add(lines, new);
}

int		check_line(t_fdf *fdf, t_list **lines, char *line)
{
	char	**split;
	int		nb_cols;

	if (!(split = ft_split(line, ' ')))
		return (print_sys_error(errno));
	nb_cols = -1;
	while (split[++nb_cols])
		if (!ft_is_nb(split[nb_cols]))
		{
			ft_free_split(split);   //fonction a ajouter de ma lib
			return (print_input_error(fdf, 1));
		}
	if (!nb_cols || (fdf->nb_cols && nb_cols != fdf->nb_cols))
	{	
		ft_free_split(split);
		print_input_error(fdf, 2);
	}
	return (append_line(lines, split));
}

int		parse_map(t_fdf *fdf, int fd)
{
	char	*line;
	char	*str;
	t_list	*lines;
	int		ret;

	line = NULL;
	str = NULL;
	while ((ret = get_next_line2(fd, &line, &str)) > 0)
	{
		if ((ret = check_line(fdf, &lines, line)))
			break ;
		ft_strdel(&line);
		(fdf->nb_rows)++;
	}
	ft_strdel(&line);
	ft_strdel(&str);
	if (ret)
	{
	//	ft_free_list(lines);	// fonction a creeri --> avant ca check lstdel	
		return (ret == -1 ? print_sys_error(errno) : 1);
	}
	ret = copy_list_to_tab(fdf, lines);
//	ft_free_list(lines);	// fonction a creer --> avant ca check lstdel	
	return (ret);
}

int		main(int ac, char **av)
{
	t_fdf	fdf;
	int		ret;
	int		fd;

	if (ac != 2)
		return (print_usage());
	if ((fd = open(av[1], O_RDONLY) == -1))
		return (print_sys_error(errno));
	ft_bzero(&fdf);
	line = NULL;
	buf = NULL;
	ret = parse_map(&fdf, fd);
	if (!ret)
		ret = init_fdf(&fdf);
	if (!ret)
		fdf_main_loop(&fdf);
	free_fdf(&fdf);
	return (ret);
}
