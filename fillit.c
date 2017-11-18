/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:45:53 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/18 15:13:12 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "get_next_line.h"

static	void	ft_usage(void)
{
	ft_putstr("usage: ./fillit file\n");
}

static	int		read_and_fill(char ***tab, char *path)
{
	char	*s;
	char	*temp;
	char	*l;
	int		fd;
	int		ret;

	fd = open(path, O_RDONLY);
	temp = NULL;
	while ((ret = get_next_line(fd, &s)) == 1)
	{
		l = temp;
		temp = ft_strjoin(temp, s);
		ft_strdel(&l);
		ft_strdel(&s);
	}
	if (ret == -1
			|| (!(*tab = ft_strsplit(temp, '\n'))))
		return (0);
	ft_strdel(&temp);
	return (1);
}

int				main(int ac, char **av)
{
	char	**tab;
	t_lst	*new;

	if (ac != 2)
	{
		ft_usage();
		return (0);
	}
	tab = NULL;
	new = NULL;
	if ((read_and_fill(&tab, av[1]) == 0)
			|| (check_tab(tab) == 0)
			|| ((new = create_list(tab)) == NULL)
			|| (fill_tab(new) == 0))
	{
		ft_putstr("error\n");
		return (-1);
	}
	ft_tabdel(tab);
	return (0);
}
