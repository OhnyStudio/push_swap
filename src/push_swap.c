/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:27 by jsavard           #+#    #+#             */
/*   Updated: 2023/02/08 22:29:02 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_push **stack, int argc, char **argv)
{
	t_push	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = create_new_node(ft_atoi(args[i]));
		add_back_stack(stack, new);
		i++;
	}
}

static void	ft_print_list(t_push **a)
{
	t_push	*temp;

	temp = (t_push *)malloc(sizeof(t_push));
	temp = *a;
	while (temp)
	{
		ft_putnbr_fd(temp->value, 1);
		ft_putstr_fd("\n", 1);
		temp = temp->next;
	}
}

static int	ft_error_message(char *str)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_push	**a;
	t_push	**b;

	if (argc < 2)
		return (ft_error_message("Wrong paramaters!"));
	else
	{
		if (is_int(argv) != 0 && check_twin(argv) != 0)
		{
			a = (t_push **)malloc(sizeof(t_push));
			b = (t_push **)malloc(sizeof(t_push));
			*a = NULL;
			*b = NULL;
			init_stack(a, argc, argv);
		}
		else
			return (ft_error_message("Wrong numbers!"));
	}
	ft_print_list(a);
	if (is_sorted(a) == 0)
	{
		sort_stack(a, b);
		ft_print_list(a);
	}
	return (0);
}
