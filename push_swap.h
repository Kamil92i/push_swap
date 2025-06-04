/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberraho <kberraho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:03:22 by kberraho          #+#    #+#             */
/*   Updated: 2025/06/04 18:00:19 by kberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				valeur;
	int				index;
	int				cout;
	int				mediane;
	int				cheapest;
	struct s_list	*noeud;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				sa(t_list **a, int print);
void				sb(t_list **b, int print);
void				ss(t_list **a, t_list **b, int print);
void				ra(t_list **a, int print);
void				rb(t_list **b, int print);
void				rr(t_list **a, t_list **b, int print);
void				rra(t_list **a, int print);
void				rrb(t_list **b, int print);
void				rrr(t_list **a, t_list **b, int print);
void				pa(t_list **a, t_list **b, int print);
void				pb(t_list **b, t_list **a, int print);
int					error_syntax(char *s);
int					error_duplicate(t_list *a, int n);
void				free_stack(t_list **stack);
int					free_errors(t_list **a);
void				free_split(char **split);
char				**split(char *s, char c);
int					init_stack_a(t_list **a, char **argv);
t_list				*trouver_noeud_optimal(t_list *stack);
void				preparer_pour_push(t_list **stack, t_list *top, char name);
void				rotate_both(t_list **a, t_list **b, t_list *cheapest_noeud);
void				rev_rotate_both(t_list **a, t_list **b,
						t_list *cheapest_noeud);
int					stack_len(t_list *stack);
int					stack_trie(t_list *stack);
t_list				*trouver_dernier(t_list *stack);
t_list				*trouver_min(t_list *stack);
t_list				*trouver_max(t_list *stack);
void				indexer_pile(t_list *stack);
void				init_noeud_a(t_list *a, t_list *b);
void				init_noeud_b(t_list *a, t_list *b);
void				marquer_moins_cher(t_list *stack);
void				tri_trois(t_list **a);
void				trier_stack(t_list **a, t_list **b);
void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_putnbr(int n);
int					ft_isdigit(int c);
void				push_swap(t_list **a);

#endif