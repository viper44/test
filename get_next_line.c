/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:24:19 by msemenov          #+#    #+#             */
/*   Updated: 2017/12/13 13:24:21 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int				ft_cut(char **str)
{
	char				*result;
	int					i;

	i = 0;
	result = *str;
	if ((ft_strchr(*str, '\n')) == 0)
	{
		if (*str != NULL)
			ft_strdel(str);
		return (1);
	}
	*str = ft_strdup(ft_strchr(*str, '\n') + 1);
	free(result);
	return (1);
}

int						get_next_line(const int fd, char **line)
{
	int					size;
	char				*buffer;
	static char			*t[50000];

	size = 1;
	buffer = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || fd > 50000 || !buffer)
		return (-1);
	if (t[fd] == NULL)
		t[fd] = ft_strnew(0);
	while ((size = read(fd, buffer, BUFF_SIZE)))
	{
		if (size == -1)
			return (-1);
		buffer[size] = '\0';
		t[fd] = ft_strjoin(t[fd], buffer);
		if ((ft_strchr(t[fd], '\n')))
			break ;
	}
	ft_strdel(&buffer);
	ft_strchr(t[fd], '\n') == 0 ? *line = ft_strsub(t[fd], 0, ft_strlen(t[fd]))
	: (*line = ft_strsub(t[fd], 0, (ft_strchr(t[fd], '\n') - t[fd])));
	if (t[fd][0] == '\0')
		return (0);
	return (ft_cut(&t[fd]));
}
