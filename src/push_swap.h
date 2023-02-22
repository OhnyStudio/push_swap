/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:52 by jsavard           #+#    #+#             */
/*   Updated: 2023/02/22 15:57:48 by jsavard          ###   ########.fr       */
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

//Algo Complexe
void	swap_to_b(t_push **a, t_push **b, int size);
void	insert_to_b(t_push **a, t_push **b, int min, int max);
//Algo Utils
int		ra_or_rra(t_push **stack, int max);
void	split_median(t_push **stack_a, t_push **stack_b);
void	min_to_top(t_push **stack_a, t_push **stack_b, int min);
void	set_backward(t_push **stack_a, t_push **stack_b, int max);
void	make_rotation(t_push **stack_a, t_push **stack_b, int max);
//Validation
int		is_int(char **argv);
int		check_twin(char	**argv);
int		is_sorted(t_push **stack);
int		stack_size(t_push *stack);
int		other_smaller(int value, int other_value);
//Algo
void	sort_stack(t_push **stack_a, t_push **stack_b);
//Base action
int		send_action(char *action, t_push **a, t_push **b, int is_print);
//List creator
void	add_back_stack(t_push **stack, t_push *new);
void	add_front_stack(t_push **stack, t_push *new);
void	set_index(t_push **stack, int current_min, int index);
//List validation Other
int		find_if_rotate(t_push **stack);
int		find_if_backward(t_push **stack);
int		count_rotation(t_push **stack, int value);
void	ft_print_list(t_push **a);
//List validation
int		is_int(char **argv);
int		check_twin(char	**argv);
int		is_sorted(t_push **stack);
int		stack_size(t_push *stack);
int		other_smaller(int value, int other_value);
//List value finder
int		find_min(t_push	**stack);
int		find_max(t_push	**stack);
int		find_tail(t_push **stack);
int		find_median(t_push **stack);
#endif