/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:33:51 by nali              #+#    #+#             */
/*   Updated: 2022/02/17 12:27:39 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	5
# endif

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct stack
{
	int				num;
	struct stack	*next;
	struct stack	*prev;
}				t_stack;

//push swap.c
int		ft_check_if_sorted(t_stack *stk);
int		*ft_input_args_check(int argc, char **argv, int *l);
t_stack	*start_sorting(t_stack *stacka, t_stack *stackb, int len, int *numarr);
void	ft_free_function(t_stack **stacka, int *numarr);
//input check store
int		*ft_check_n_store(char **str, int len);
int		ft_strcmp(const char *s1, const char *s2);
//small sorting
void	sort_two(t_stack *stk, char ch);
t_stack	*sort_three(t_stack *stk, char ch);
t_stack	*sort_four(t_stack *stacka, t_stack *stackb);
t_stack	*sort_five(t_stack *stacka, t_stack *stackb);
//big sorting
t_stack	*sort_upto_hundred(t_stack *stacka, t_stack *stackb, int l, int *narr);
t_stack	*sort_above_hundred(t_stack *stacka, t_stack *stackb, int l, int *arr);
void	ft_get_val_limits(t_stack **a, t_stack **b, long long l1, long long l2);
//sorting algo
void	ft_quicksort(int *num, int first, int last);
void	sort_array(int *num, int len);
//operations & operation two
void	swap(t_stack *stk, char ch);
void	swap_s(t_stack *stk1, t_stack *stk2);
void	rotate(t_stack **stk, char ch);
void	rotate_reverse(t_stack **stk, char ch);
void	push(t_stack **from, t_stack **to, char ch);
void	rotate_r(t_stack **stk1, t_stack **stk2);
void	rotate_reverse_r(t_stack **stk1, t_stack **stk2);
// stack operations
t_stack	*ft_new_node(int number, t_stack *head);
t_stack	*ft_add_node_begin(int number, t_stack *head);
t_stack	*ft_populate_stack(int len, int *narray);
// small_sorting_utils
void	ft_insert_to_position(t_stack **stka, t_stack **stkb);
// push swap utils
int		find_median_ll(t_stack *stk);
int		find_num_elements(t_stack *stk);
int		ft_find_num_pos(t_stack *stk, int num);
int		find_median_array(int *numarr, int len);
void	free_linked_list(t_stack **stk);
//big sorting utils
int		ft_perform_min_moves(t_stack **stkb, t_stack **stka, int len, int *r);
//big sorting utils two
int		ft_find_min(t_stack *stk);
int		ft_find_max(t_stack *stk);
void	sort_stackb_pushto_stacka(t_stack **stka, t_stack **stkb);
//checker_utils
int		check_if_valid_instruction(char *buf);
void	perform_action_stack(t_stack **stka, t_stack **stkb, char *buf);
char	*get_instruction(char *buf);
void	write_to_file(int fd);
//get next line
char	*get_next_line(int fd);
int		ft_findlen(const char *s);
char	*str_concat(char *s1, const char *s2);
//big_sorting_five_hundred
int		get_median(long long min, long long max, int *arr, int l);
//input_string_processing.c 
char	**handle_input_string(int argc, char **argv);
#endif