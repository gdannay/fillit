/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:10:05 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/18 18:25:27 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static	void			fill_blocs(t_lst *new, int *t, int i, int j)
{
	if (*t == 1)
	{
		new->bloc1.x = i % 5;
		new->bloc1.y = j % 5;
	}
	else if (*t == 2)
	{
		new->bloc2.x = i % 5;
		new->bloc2.y = j % 5;
	}
	else if (*t == 3)
	{
		new->bloc3.x = i % 5;
		new->bloc3.y = j % 5;
	}
	else if (*t == 4)
	{
		new->bloc4.x = i % 5;
		new->bloc4.y = j % 5;
	}
	*t = *t + 1;
}

static	t_lst			*ft_newlst(char **tab, int i, int j, char c)
{
	t_lst	*new;
	int		a;
	int		t;

	new = NULL;
	if (!(new = (t_lst *)ft_memalloc(sizeof(t_lst))))
		return (NULL);
	new->c = c;
	a = i;
	t = 1;
	while (i < a + 4)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				fill_blocs(new, &t, i, j);
			j++;
		}
		i++;
	}
	new->next = NULL;
	return (new);
}

t_lst					*create_list(char **tab)
{
	char	c;
	int		i;
	t_lst	*tmp;
	t_lst	*tmp2;
	t_lst	*new;

	c = 'A';
	i = 0;
	tmp = ft_newlst(tab, i, 0, c);
	new = tmp;
	tmp2 = tmp;
	c++;
	while (tab[i])
	{
		if ((i + 1) % 5 == 0)
		{
			tmp = ft_newlst(tab, i, 0, c);
			tmp2->next = tmp;
			tmp2 = tmp;
			c++;
		}
		i++;
	}
	return (new);
}
