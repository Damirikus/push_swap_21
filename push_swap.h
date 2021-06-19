#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
int css;
typedef struct s_flags
{
	int	count;
	int	max_count_for_markup;
	int	max_dig;
	int	max_markup_position;
}		t_flags;
typedef struct s_alg
{
	int			rb;
	int			rrb;
	int			ra;
	int			rra;
	int			rr1;
	int			rrr2;
	int			rarrb3;
	int			rbrra4;
	int			a_order_find;
	int			len_stack_b;
	int			len_stack_a;
	int			max_order;
	int			max_actions;
	int			f;
	int			min;
}				t_alg;
int		ft_chek(char *str, t_list **stack_a);
int		ft_init(t_list **stack_a, long cont);
int		ft_distributor(t_list **stack_a);
void	ft_swap(t_list **stack_a, t_list **stack_b, int var);
int		ft_check_max_min(char *str);
void	ft_push(t_list **stack_a, t_list **stack_b, int var);
void	ft_rt(t_list **stack_a, t_list **stack_b, int var);
void	ft_rrtt(t_list **stack_a, t_list **stack_b, int var);
void	ft_to_3(t_list **stack_a, int len);
void	ft_to_5(t_list **stack_a, t_list **stack_b, int len);
int		ft_minimum(t_list **stack_a);
int		ft_position_min(t_list **stack_a, int min);
void	upordown(t_list **stack_a, int position_min, int res);
int		ft_masscheck(int *massfororder, int len);
void	sort_mass(int *massfororder, t_list **stack_a, int len);
void	init_orders(int *massfororder, t_list **stack_a, int len);
void	ft_first(t_list **stack_a, t_list **stack_b);
void	ft_zeroing(t_flags *flags, t_alg *action);
void	ft_main_algorithm(t_list **stack_a, t_list **stack_b, t_alg *action);
int		ft_len_stack(t_list **stack);
void	ft_parcing(t_alg *action, int ord);
void	ft_find_begin_markup(t_list **stack_a, t_flags *flags);
void	ft_markuping(t_list **stack_a, t_flags *flags);
void	ft_push_b(t_list **stack_a, t_list **stack_b, int len);
void	ft_find_order_stack_a(t_list **stack_a, t_alg *action, int ord);
void	ft_mooving_stack_a(t_list **stack_a, t_alg *action);
void	ft_actions(t_list **stack_a, t_list **stack_b, t_alg *action);
void	ft_new_steps(t_list **stack_a, t_list **stack_b, t_alg *action);
void	ft_traffic(t_list **stack_a);
void	ft_swap2(t_list **stack_b, t_list *third);
void	ft_rt2(t_list **stack_b, t_list *temp, int var);
void	ft_rrtt2(t_list **stack_b, t_list *temp, int var);
void	ft_to_3_con(t_list **stack_a, t_list *one, t_list *two, t_list *three);
void	ft_find_begin_markup_inner(t_list **stack_a, t_flags *flags, int cur);
void	ft_first_action_two(t_list **stack_a, t_list **stack_b, t_alg *action);
void	ft_first_action(t_list **stack_a, t_list **stack_b, t_alg *action);
void	ft_second_action(t_list **stack_a, t_list **stack_b, t_alg *action);
void	ft_second_action_two(t_list **stack_a, t_list **stack_b, t_alg *action);
void	ft_third_action(t_list **stack_a, t_list **stack_b, t_alg *action);
void	ft_fourth_action(t_list **stack_a, t_list **stack_b, t_alg *action);
void	ft_errors(int a);
void	ft_disti(int *massfororder, t_list **stack_a, \
t_list **stack_b, int len);
void	ft_markup_next(int cur, t_flags *flags, t_list **stack_a);
void	ft_traffic_helper(int i, t_list **stack_a);
void ft_printf_b(t_list **stack_b);
void ft_printf_a(t_list **stack_a);
int ft_len_split(char **masssplit);
#endif