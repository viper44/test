/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:24:28 by msemenov          #+#    #+#             */
/*   Updated: 2017/11/15 12:43:44 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *b, size_t length)
{
	size_t			i;
	unsigned char	*bi;

	i = 0;
	bi = b;
	while (i < length)
	{
		bi[i] = '\0';
		i++;
	}
}
