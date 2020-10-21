/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:46:07 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 21:52:24 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_reverse_rotates(char *line, t_start *start)
{
	if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate_a(start);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate_b(start);
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_rotate_r(start);
}

void	reverse_rotate_a(t_start *start)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (start->list_a != NULL)
	{
		if (start->list_a->next != NULL)
		{
			last = start->list_a;
			penultimate = start->list_a;
			while ((penultimate->next)->next != NULL)
				penultimate = penultimate->next;
			while (last->next != NULL)
				last = last->next;
			penultimate->next = NULL;
			last->next = start->list_a;
			start->list_a = last;
		}
	}
}

void	reverse_rotate_b(t_start *start)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (start->list_b != NULL)
	{
		if (start->list_b->next != NULL)
		{
			last = start->list_b;
			penultimate = start->list_b;
			while ((penultimate->next)->next != NULL)
				penultimate = penultimate->next;
			while (last->next != NULL)
				last = last->next;
			penultimate->next = NULL;
			last->next = start->list_b;
			start->list_b = last;
		}
	}
}

void	reverse_rotate_r(t_start *start)
{
	reverse_rotate_a(start);
	reverse_rotate_b(start);
}
