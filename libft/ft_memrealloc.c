/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:29:02 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/13 19:57:20 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(const void *s, size_t old, size_t new)
{
	void	*tmp;

	if (!(tmp = ft_memalloc(new + old)))
		return (NULL);
	if (!s)
		return (tmp);
	tmp = ft_memcpy(tmp, s, old);
	free((void *)s);
	return (tmp);
}
