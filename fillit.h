/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:45:20 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/18 15:12:34 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef	struct		s_lst
{
	t_pos			bloc1;
	t_pos			bloc2;
	t_pos			bloc3;
	t_pos			bloc4;
	char			c;
	struct s_lst	*next;
}					t_lst;

typedef	struct		s_algo
{
	char			**tab_final;
	int				size_final;
	char			**tab;
	int				size;
	int				nb_tetri;
	t_lst			*new;
}					t_algo;

int					lentab(char **tab);
void				print_list(t_lst *new);
t_lst				*create_list(char **tab);
int					check_tab(char **tab);
int					fill_tab(t_lst *new);
void				ft_putfillit(char **tab, int size);
int					algo(t_algo *algo, int i, int j, int bloc);
int					ft_lenlst(t_lst *new);
void				move_bloc(t_lst *new);
int					write_bloc(t_algo *alg, int i, int j, int bloc);
void				erase_bloc(t_algo *alg, int i, int j, int bloc);
void				erase(char **tab);
void				ft_tabdup(t_algo *alg);
int					fill_tab(t_lst *beg);
int					check(t_algo *alg, int i, int j, int bloc);
char				**cp(t_lst *beg);
void				ft_dellst(t_lst **new);

#endif
