/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:44:47 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 21:52:24 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_pushs(char *line, t_start *start)
{
	if (ft_strcmp(line, "pa\n") == 0)
		push_a(start);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_b(start);
}

void	push_a(t_start *start)
{
	t_stack	*to_push;

	if (start->list_b != NULL)
	{
		to_push = start->list_b;
		start->list_b = to_push->next;
		to_push->next = start->list_a;
		start->list_a = to_push;
	}
}

void	push_b(t_start *start)
{
	t_stack	*to_push;

	if (start->list_a != NULL)
	{
		to_push = start->list_a;
		start->list_a = to_push->next;
		to_push->next = start->list_b;
		start->list_b = to_push;
	}
}
