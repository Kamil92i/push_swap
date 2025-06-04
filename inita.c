/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inita.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberraho <kberraho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:01:42 by kberraho          #+#    #+#             */
/*   Updated: 2025/06/04 18:00:31 by kberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexer_pile(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->mediane = 1;
		else
			stack->mediane = 0;
		stack = stack->next;
		++i;
	}
}

static void	definir_cible_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*noeud;
	long	best_m_i;

	while (a)
	{
		best_m_i = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->valeur < a->valeur && current_b->valeur > best_m_i)
			{
				best_m_i = current_b->valeur;
				noeud = current_b;
			}
			current_b = current_b->next;
		}
		if (best_m_i == LONG_MIN)
			a->noeud = trouver_max(b);
		else
			a->noeud = noeud;
		a = a->next;
	}
}

static void	calcul_cout_a(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cout = a->index;
		if (!(a->mediane))
			a->cout = len_a - (a->index);
		if (a->noeud->mediane)
			a->cout += a->noeud->index;
		else
			a->cout += len_b - (a->noeud->index);
		a = a->next;
	}
}

void	marquer_moins_cher(t_list *stack)
{
	long	cheapest_valeur;
	t_list	*cheapest_noeud;

	if (!stack)
		return ;
	cheapest_valeur = LONG_MAX;
	while (stack)
	{
		if (stack->cout < cheapest_valeur)
		{
			cheapest_valeur = stack->cout;
			cheapest_noeud = stack;
		}
		stack = stack->next;
	}
	cheapest_noeud->cheapest = 1;
}

void	init_noeud_a(t_list *a,	 t_list *b)
{
	indexer_pile(a);
	indexer_pile(b);
	definir_cible_a(a, b);
	calcul_cout_a(a, b);
	marquer_moins_cher(a);
}
