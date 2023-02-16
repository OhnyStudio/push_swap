/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:52 by jsavard           #+#    #+#             */
/*   Updated: 2023/02/16 15:54:37 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_push
{
	int				value;
	int				index;
	struct s_push	*next;
}	t_push;

//Validation
int		is_int(char **argv);
int		check_twin(char	**argv);
int		is_sorted(t_push **stack);
int		stack_size(t_push *stack);
//List Utils
void	add_back_stack(t_push **stack, t_push *new);
void	add_front_stack(t_push **stack, t_push *new);
void	sort_stack(t_push **stack_a, t_push **stack_b);
t_push	*create_new_node(int value);
//Move action
int		send_action(char *action, t_push **a, t_push **b, int is_print);
//Find
int		find_min(t_push	**stack);
int		find_max(t_push	**stack);
int		ra_or_rra(t_push **stack, int max);
void	set_index(t_push **stack, int next_min, int index);
//Algo
void	algo2(t_push **stack_a, t_push **stack_b);
void	algo3(t_push **stack_a, t_push **stack_b, int min, int max);
void	algo4(t_push **stack_a, t_push **stack_b, int min, int max);
void	algo_other(t_push **stack_a, t_push **stack_b, int min, int max);
//Algo Utils
int		find_if_rotate(t_push **stack);
int		find_if_backward(t_push **stack);
void	min_to_top(t_push **stack_a, t_push **stack_b, int min);
void	make_rotation(t_push **stack_a, t_push **stack_b, int max);
void	set_backward(t_push **stack_a, t_push **stack_b, int max);
//Algo Other]
void	new_algo(t_push **stack_a, t_push **stack_b, int min, int max);
//Test fonction
int		find_median(t_push **stack);
int		find_tail(t_push **stack);
int		count_rotation(t_push **stack, int new);
int		other_smaller(int value, int other_value);
void	ft_print_list(t_push **a);
void	split_median(t_push **stack_a, t_push **stack_b);

#endif