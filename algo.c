/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:47:48 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/18 18:32:01 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	void	fill_alg(t_algo *alg)
{
	erase(alg->tab_final);
	ft_tabdup(alg);
	alg->size_final = alg->size;
	erase(alg->tab);
	alg->size = alg->size - 1;
	algo(alg, 0, 0, 0);
}

static	void	incr_val(t_algo *alg, int *i, int *j)
{
	if (*j < alg->size)
		*j = *j + 1;
	else
	{
		*i = *i + 1;
		*j = 0;
	}
}

static	int		boolean(int bloc, t_algo *alg)
{
	if (bloc == alg->nb_tetri)
		return (1);
	return (0);
}

int				algo(t_algo *alg, int i, int j, int bloc)
{
	if (bloc == alg->nb_tetri || i > alg->size)
		return (boolean(bloc, alg));
	if (check(alg, i, j, bloc))
	{
		write_bloc(alg, i, j, bloc);
		if (algo(alg, 0, 0, bloc + 1))
		{
			if (bloc == 0)
				fill_alg(alg);
			return (1);
		}
		else
		{
			erase_bloc(alg, i, j, bloc);
			if (algo(alg, i, j + 1, bloc))
				return (1);
		}
	}
	else
	{
		incr_val(alg, &i, &j);
		if (algo(alg, i, j, bloc))
			return (1);
	}
	return (0);
}
