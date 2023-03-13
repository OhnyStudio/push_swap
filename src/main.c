/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:27 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/13 16:49:12 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_error_message(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (-1);
}

static int	validate_nb(char *str)
{
	int					i;
	int					signe;
	unsigned long long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	if (str[i] == '\0')
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9' || str[i] == '\0')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (check_max_min_int(nb, signe));
}

static t_push	*create_new_node(int value)
{
	t_push	*new_list;

	new_list = (t_push *)malloc(sizeof(t_push));
	if (!new_list)
		return (NULL);
	new_list->value = value;
	new_list->next = NULL;
	return (new_list);
}

static int	init_stack(t_push **stack, int argc, char **argv)
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
	if (check_twin(args) != 0 && is_int(args) != 0)
	{
		while (args[i])
		{
			if (validate_nb(args[i]) != -1)
			{
				new = create_new_node(ft_atoi(args[i]));
				add_back_stack(stack, new);
				i++;
			}
			else
				return (-1);
		}
	}
	else
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_push	**a;
	t_push	**b;

	if (argc < 2)
		return (0);
	a = (t_push **)malloc(sizeof(t_push));
	b = (t_push **)malloc(sizeof(t_push));
	*a = NULL;
	*b = NULL;
	if (init_stack(a, argc, argv) != -1)
	{
		if (is_sorted(a) == 0)
			sort_stack(a, b);
	}
	else
		return (ft_error_message("Wrong numbers!"));
	free_list(a);
	free_list(b);
	return (0);
}
