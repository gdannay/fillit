/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:49:00 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/18 18:22:24 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	int	check_char_len(char **tab, int i, int j, int *t)
{
	if ((lentab(tab) + 1) % 5 != 0)
		return (0);
	if ((i + 2) % 5 == 0 && j == 4)
	{
		if (*t != 4)
			return (0);
		*t = 0;
	}
	if ((i + 1) % 5 == 0)
	{
		if (ft_strlen(tab[i]) != 1 || tab[i][0] != '\n')
			return (0);
	}
	else
	{
		if (ft_strlen(tab[i]) != 5 || (tab[i][j] != '\n'
					&& tab[i][j] != '.' && tab[i][j] != '#'))
			return (0);
	}
	return (1);
}

static	int	check_bloc2(char **tab, int i, int j, int *k)
{
	if ((i + 2) % 5 == 0 && j == 4)
	{
		if (*k == 0)
			return (0);
		*k = 0;
	}
	if (tab[i][j] == '#')
	{
		if (((i % 5 > 0 && tab[i - 1][j] == '#')
				&& ((i + 2) % 5 > 0 && tab[i + 1][j] == '#'))
			|| ((i % 5 > 0 && tab[i - 1][j] == '#')
				&& (j - 1 >= 0 && tab[i][j - 1] == '#'))
			|| ((i % 5 > 0 && tab[i - 1][j] == '#')
				&& (j + 1 <= 4 && tab[i][j + 1] == '#'))
			|| (((i + 2) % 5 > 0 && tab[i + 1][j] == '#')
				&& (j - 1 >= 0 && tab[i][j - 1] == '#'))
			|| (((i + 2) % 5 > 0 && tab[i + 1][j] == '#')
				&& (j + 1 <= 4 && tab[i][j + 1] == '#'))
			|| ((j - 1 >= 0 && tab[i][j - 1] == '#')
				&& (j + 1 <= 4 && tab[i][j + 1] == '#')))
			*k = *k + 1;
	}
	return (1);
}

static	int	check_bloc(char **tab, int i, int j)
{
	if (tab[i][j] == '#')
	{
		if ((i % 5 > 0 && tab[i - 1][j] == '#')
			|| ((i + 2) % 5 > 0 && tab[i + 1][j] == '#')
			|| (j - 1 >= 0 && tab[i][j - 1] == '#')
			|| (j + 1 <= 4 && tab[i][j + 1] == '#'))
			return (1);
		return (0);
	}
	return (1);
}

int			check_tab(char **tab)
{
	int		i;
	int		j;
	int		t;
	int		k;

	i = 0;
	t = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!(check_char_len(tab, i, j, &t)) || !(check_bloc(tab, i, j))
				|| !(check_bloc2(tab, i, j, &k)))
				return (0);
			if (tab[i][j] == '#')
				t++;
			j++;
		}
		i++;
	}
	if (i > 129)
		return (0);
	return (1);
}
