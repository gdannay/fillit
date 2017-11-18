/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:19:35 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/18 18:19:05 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		lentab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_dellst(t_lst **new)
{
	t_lst	*tmp;

	while (*new)
	{
		tmp = (*new)->next;
		free(*new);
		(*new) = tmp;
	}
	*new = NULL;
}

int		ft_lenlst(t_lst *new)
{
	t_lst	*tmp;
	int		i;

	tmp = new;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_putfillit(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j <= size)
			ft_putchar(tab[i][j++]);
		ft_putchar('\n');
		i++;
	}
}
