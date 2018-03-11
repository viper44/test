/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:57:49 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/16 13:57:50 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_data
{
	int			player;
	int			flag;
	int			flag_bad;
	int			end;
}				t_data;

typedef struct		s_chain
{
	int				value;
	struct s_chain	*next;
	struct s_chain	*prev;
}					t_chain;


#endif