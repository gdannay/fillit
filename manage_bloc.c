/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_bloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:54:18 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/16 20:03:30 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	move_bloc(t_lst *new)
{
	t_lst	*tmp;

	tmp = new;
	while (tmp)
	{
		while (tmp->bloc1.x > 0 && tmp->bloc2.x > 0
				&& tmp->bloc3.x > 0 && tmp->bloc4.x > 0)
		{
			tmp->bloc1.x--;
			tmp->bloc2.x--;
			tmp->bloc3.x--;
			tmp->bloc4.x--;
		}
		while (tmp->bloc1.y > 0 && tmp->bloc2.y > 0
				&& tmp->bloc3.y > 0 && tmp->bloc4.y > 0)
		{
			tmp->bloc1.y--;
			tmp->bloc2.y--;
			tmp->bloc3.y--;
			tmp->bloc4.y--;
		}
		tmp = tmp->next;
	}
}

int		write_bloc(t_algo *alg, int i, int j, int bloc)
{
	t_lst	*tmp;
	int		k;

	tmp = alg->new;
	k = 0;
	while (k < bloc)
	{
		tmp = tmp->next;
		k++;
	}
	alg->tab[tmp->bloc1.x + i][tmp->bloc1.y + j] = tmp->c;
	alg->tab[tmp->bloc2.x + i][tmp->bloc2.y + j] = tmp->c;
	alg->tab[tmp->bloc3.x + i][tmp->bloc3.y + j] = tmp->c;
	alg->tab[tmp->bloc4.x + i][tmp->bloc4.y + j] = tmp->c;
	return (1);
}

void	erase_bloc(t_algo *alg, int i, int j, int bloc)
{
	t_lst	*tmp;
	int		k;

	tmp = alg->new;
	k = 0;
	while (k < bloc)
	{
		tmp = tmp->next;
		k++;
	}
	alg->tab[tmp->bloc1.x + i][tmp->bloc1.y + j] = '.';
	alg->tab[tmp->bloc2.x + i][tmp->bloc2.y + j] = '.';
	alg->tab[tmp->bloc3.x + i][tmp->bloc3.y + j] = '.';
	alg->tab[tmp->bloc4.x + i][tmp->bloc4.y + j] = '.';
}

void	erase(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			tab[i][j++] = '.';
		i++;
	}
}

void	ft_tabdup(t_algo *alg)
{
	int		i;
	int		j;

	i = 0;
	while (i < ft_lenlst(alg->new) * 4)
	{
		j = 0;
		while (j < ft_lenlst(alg->new) * 4)
		{
			alg->tab_final[i][j] = alg->tab[i][j];
			j++;
		}
		alg->tab_final[i][j] = '\0';
		i++;
	}
	alg->tab_final[i] = NULL;
}
