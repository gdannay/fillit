/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:47:00 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/13 21:47:26 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static	int	check_char(char **tmp, char **line)
{
	char	*l;

	if (ft_strchr(*tmp, CHAR))
	{
		*line = ft_strsub(*tmp, 0, ft_strchr(*tmp, CHAR) - *tmp + 1);
		l = *tmp;
		*tmp = ft_strsub(*tmp, ft_strchr(*tmp, CHAR) - *tmp + 1,
				ft_strlen(*tmp));
		ft_strdel(&l);
		return (1);
	}
	else if (ft_strlen(*tmp) > 0 && *tmp[0] != '\0' && ft_strchr(*tmp, '\0'))
	{
		*line = ft_strdup(*tmp);
		ft_strdel(tmp);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static	char	*tmp = NULL;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (line == NULL || fd < 0)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while (ft_strchr(tmp, CHAR) == NULL
			&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = ft_memrealloc(tmp, ft_strlen(tmp), BUFF_SIZE + 1);
		tmp = ft_strcat(tmp, buff);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	if (ret == -1)
		return (-1);
	return (check_char(&tmp, line));
}
