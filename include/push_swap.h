/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:52 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/08 10:16:23 by johnysavard      ###   ########.fr       */
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

//Algo Utils
int		ra_or_rra(t_push **stack, int max);
void	min_to_top_4(t_push **stack_a, t_push **stack_b, int min);
void	min_to_top_5(t_push **stack_a, t_push **stack_b, int min);
void	set_backward(t_push **stack_a, t_push **stack_b, int max);
void	make_rotation(t_push **stack_a, t_push **stack_b, int max);
//Algo Big Utils

//Validation
int		is_int(char **argv);
int		check_twin(char	**argv);
int		is_sorted(t_push **stack);
int		stack_size(t_push *stack);
int		is_reverse_sorted(t_push **stack);
//Algo
void	sort_stack(t_push **stack_a, t_push **stack_b);
//Algo 6
void	algo6(t_push **stack_a, t_push **stack_b, int min, int max);
void	split_stack_nb(t_push **stack_a, t_push **stack_b, int nb_split, int i);
//Algo Big
void	big_algo(t_push **stack_a, t_push **stack_b, int min, int max);
//Base action
int		send_action(char *action, t_push **a, t_push **b, int is_print);
//List Check Bit
void	check_bit(t_push **stack_a, t_push **stack_b, int n);
//List creator
void	add_back_stack(t_push **stack, t_push *new);
void	add_front_stack(t_push **stack, t_push *new);
void	set_index(t_push **stack, int current_min, long index);
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
int		find_min(t_push	**stack, int needindex);
int		find_max(t_push	**stack, int needindex);
int		find_tail(t_push **stack, int needindex);
int		find_median(t_push **stack);
//Send Actions
void	send_actions_print(char *actions, t_push **a, t_push **b, int count);
void	send_actions_no_print(char *actions, t_push **a, t_push **b, int count);
#endif