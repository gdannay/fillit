/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:01:37 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/18 18:32:38 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	t_algo	*fill_algo(t_lst *beg)
{
	t_algo	*alg;

	if (!(alg = (t_algo *)ft_memalloc(sizeof(t_algo))))
		return (NULL);
	alg->tab_final = cp(beg);
	alg->size_final = 0;
	alg->tab = cp(beg);
	alg->size = ft_lenlst(beg) * 4;
	alg->new = beg;
	alg->nb_tetri = ft_lenlst(beg);
	return (alg);
}

int				fill_tab(t_lst *beg)
{
	t_algo	*alg;

	move_bloc(beg);
	alg = fill_algo(beg);
	algo(alg, 0, 0, 0);
	ft_putfillit(alg->tab_final, alg->size_final);
	ft_tabdel(alg->tab);
	ft_tabdel(alg->tab_final);
	ft_dellst(&beg);
	free(alg);
	return (1);
}
