/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:50:38 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/13 19:49:52 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int		lt(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			len++;
		i++;
	}
	return (len);
}

static	int		size_words(char const *s, int i, char c)
{
	int		len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (s == NULL || (!(tab = ft_memalloc(sizeof(char *) * (lt(s, c) + 1)))))
		return (NULL);
	while (s[i])
	{
		k = 0;
		if (!(tab[j] = ft_memalloc(size_words(s, i, c) + 2)))
			return (NULL);
		while (s[i] && s[i] != c)
			tab[j][k++] = s[i++];
		tab[j][k++] = c;
		tab[j++][k] = '\0';
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
