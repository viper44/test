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

#include "./get_next_line/libft/libft.h"
#include "get_next_line.h"
#include "alum1.h"

t_chain	*ft_create_node(int value)
{
	t_chain *new;

	new = (t_chain*)malloc(sizeof(t_chain));
	new->value = value;
	new->next = NULL;
	return (new);
}
void	ft_get_map(t_chain **head, int fd, t_data *data)
{
	int i;
	int len;
	char *line;
	int	quit;
	t_chain *ptr;
	t_chain *new;

	ptr = *head;
	quit = 0;
	len = 0;
	i = 0;
	while(get_next_line(fd, &line))
	{
		printf("line = %s\n", line);
		len = ft_atoi(line);
		printf("len = %d\n", len);
		new = ft_create_node(len);
		printf("ooo %d\n", new->value);
		if (ptr == NULL)
		{
			printf("%s\n", "NULL or NOT ?");
			ptr = new;
			printf("ptr value = %d\n", ptr->value);
		}
		else
		{
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new;
		}
	}
	ptr = *head;
	while (ptr->next != NULL)
	{
		printf("ddd %d\n",ptr->value);
		ptr = ptr->next;
	}
}

int	main(int argc, char **argv)
{
	int	fd;
	int i;
	t_chain *head;
	t_data *data;

	head = NULL;
	i = 0;
	if (argc > 2)
	{
		write (1, "ERROR\n", 6);
		return (0);
	}
	data = ft_memalloc(sizeof(data));
	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	ft_get_map(&head, fd, data);
	// while (data->ptr_board[i])
	// {
	// 	printf("%s\n", data->ptr_board[i]);
	// 	i++;
	// }
	return (0);
}