/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:03:47 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/17 12:25:41 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		check(t_algo *alg, int i, int j, int bloc)
{
	t_lst	*tmp;
	int		k;

	tmp = alg->new;
	k = 0;
	while (tmp && k < bloc)
	{
		tmp = tmp->next;
		k++;
	}
	if (!tmp)
		return (0);
	if (tmp->bloc1.x + i > alg->size || tmp->bloc1.y + j > alg->size
			|| tmp->bloc2.x + i > alg->size || tmp->bloc2.y + j > alg->size
			|| tmp->bloc3.x + i > alg->size || tmp->bloc3.y + j > alg->size
			|| tmp->bloc4.x + i > alg->size || tmp->bloc4.y + j > alg->size)
		return (0);
	if ((alg->tab[tmp->bloc1.x + i][tmp->bloc1.y + j] == '.')
			&& (alg->tab[tmp->bloc2.x + i][tmp->bloc2.y + j] == '.')
			&& (alg->tab[tmp->bloc3.x + i][tmp->bloc3.y + j] == '.')
			&& (alg->tab[tmp->bloc4.x + i][tmp->bloc4.y + j] == '.'))
		return (1);
	return (0);
}

char	**cp(t_lst *beg)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = (char **)ft_memalloc(sizeof(char *)
					* (ft_lenlst(beg) * 4 + 1))))
		return (0);
	i = 0;
	while (i < ft_lenlst(beg) * 4)
	{
		j = 0;
		if (!(tab[i] = (char *)ft_memalloc(ft_lenlst(beg) * 4 + 1)))
			return (0);
		while (j < ft_lenlst(beg) * 4)
			tab[i][j++] = '.';
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
