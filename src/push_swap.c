/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:27 by jsavard           #+#    #+#             */
/*   Updated: 2023/02/06 17:03:06 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*create_new_node(int value)
{
	t_push	*new;

	new = malloc(sizeof(t_push));
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_print_list(t_push *a)
{
	while (a)
	{
		ft_putnbr_fd(a->value, 1);
		ft_putstr_fd("\n", 1);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_push	*a;
	t_push	*temp;
	int		i;
	int		value;

	a = NULL;
	if (argc < 2)
		return (-1);
	else
	{
		i = 1;
		while (argv[i])
		{
			value = ft_atoi(argv[i]);
			temp = create_new_node(value);
			temp->next = a;
			a = temp;
			i++;
		}
	}
	ft_print_list(a);
	return (0);
}
