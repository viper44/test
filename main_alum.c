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

// #include "libft/libft.h"
#include "get_next_line.h"
#include "alum1.h"

void	ft_remove_matches(t_chain *head, t_data *data, int value)
{
	t_chain *ptr;

	ptr = head;
	
	while (ptr->next)
		ptr = ptr->next;
	while (ptr)
	{
		while (ptr->value == 0)
		{
			if (ptr->prev == NULL)
				return ;
			ptr = ptr->prev;
		}
		ptr->value = ptr->value - value;
		data->flag = 1;
		if (head->value == 0)
		{
			printf("%s\n", "player win");
			data->end = 1;
			return;
		}
		break ;
	}

}

int ft_check_answer2(t_chain *head, int value)
{
	t_chain *ptr;

	ptr = head;
	while (ptr->next)
		ptr = ptr->next;
	while (ptr)
	{
		while (ptr->value == 0)
			ptr = ptr->prev;
		if (ptr->value < value)
		{
			//printf("ptr->val %d val %d\n", ptr->value , value);
			return (0);
		}
		else
		{
			//printf("ptr->val2 %d val2 %d\n", ptr->value , value);
			return (1);
		}
	}
	return (1);
}

int	check_answer1(char *answer)
{
	int i;

	i = 0;
	while (answer[i])
	{
		if (!ft_isdigit(answer[i]))
			return (0);
		i++;
	}
	return(1);
}

void	ft_player(t_chain **head, t_data *data)
{
	char 	*line;
	int		answer;

	answer = 0;
	while (data->flag != 1)
	{
		printf("%s\n", "please enter number of matches you want to remove");
		get_next_line(0, &line);
		answer = ft_atoi (line);
		if (!check_answer1(line))
			printf("%s\n", "your input is incorect");
		else if (answer > 3 || answer < 1)
			printf("%s\n", "your input is incorect");
		else if (answer > 0 && answer < 4 && ft_check_answer2(*head, answer))
		{
			answer = ft_atoi(line);
			ft_remove_matches(*head, data, answer);
		}
		else
			printf("%s\n", "your input is incorect");

	}
	answer = ft_atoi(line);
}

void	ft_print_map(t_chain **head)
{
	int i;
	t_chain *ptr;

	i = 0;
	ptr = *head;
	while (ptr)
	{		
		while (i < ptr->value)
		{
			printf("%c", '|');
			i++;
		}
		i = 0;
		printf("\n");
		if (ptr->next)
			ptr = ptr->next;
		else
			break;
	}
}

t_chain	*ft_create_node(int value)
{
	t_chain *new;

	new = (t_chain*)malloc(sizeof(t_chain));
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
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
	while(get_next_line(fd, &line) && *line != '\0')
	{
		len = ft_atoi(line);
		if (len < 1 || len > 10000)
		{
			write (1, "ERROR\n", 6);
			return ;
		}
		new = ft_create_node(len);
		if (ptr == NULL)
		{
			*head = new;
			ptr = *head;
		}
		else
		{
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = new;
			ptr->next->prev = ptr;
			// if (ptr->prev != NULL)
			// {
			// 	printf("ptr prev val = %d\n", ptr->prev->value);
			// 	printf("ptr current = %d\n", ptr->value);
			// }
		}
	}
	ptr = *head;
	// printf("head val = %d\n", ptr->value);
	// printf("head next = %d\n", ptr->next->value);
	// printf("prev = %d\n", ptr->prev);
	// // printf("%s\n", );
	// while (ptr)
	// {
	// 	//ft_print_map(ptr);
	// 	if (ptr->next)
	// 		ptr = ptr->next;
	// 	else
	// 		break;
	// 	//if (ptr->prev->value != 0)
	// 		//printf("prev val v cikle = %d\n", ptr->prev->value);
	// }
	// while (ptr)
	// {
	// 	printf("prev value = %d\n", ptr->value);
	// 	ptr = ptr->prev;
	// }
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
	while (data->end != 1)
	{
		ft_print_map(&head);
		ft_player(&head, data);
		ft_print_map(&head);
		data->flag = 0;
		//ft_computer(&head);
	}
	return (0);
}