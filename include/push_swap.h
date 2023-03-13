/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:52 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/13 14:15:41 by jsavard          ###   ########.fr       */
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
//Algo Binary
int		find_max_bit(int max);
void	move_bit_a(t_push **stack_a, t_push **stack_b, int bit);
void	move_bit_b(t_push **stack_a, t_push **stack_b, int bit);
//Base action
int		send_action(char *action, t_push **a, t_push **b, int is_print);
//List creator
void	add_back_stack(t_push **stack, t_push *new);
void	add_front_stack(t_push **stack, t_push *new);
void	set_index(t_push **stack, int current_min, long index);
//List split
int		split_nb(t_push **a, t_push **b, int origin_split);
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
void	send_actions(char *actions, t_push **a, t_push **b, int count);
#endif