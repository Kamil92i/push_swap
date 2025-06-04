/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberraho <kberraho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:00:36 by kberraho          #+#    #+#             */
/*   Updated: 2025/06/04 17:37:39 by kberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_list *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_list	*trouver_dernier(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_trie(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->valeur > stack->next->valeur)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_list	*trouver_min(t_list *stack)
{
	long	min;
	t_list	*min_noeud;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->valeur < min)
		{
			min = stack->valeur;
			min_noeud = stack;
		}
		stack = stack->next;
	}
	return (min_noeud);
}

t_list	*trouver_max(t_list *stack)
{
	long	max;
	t_list	*max_noeud;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->valeur > max)
		{
			max = stack->valeur;
			max_noeud = stack;
		}
		stack = stack->next;
	}
	return (max_noeud);
}
