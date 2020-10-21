/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_leaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:42:24 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/05 17:23:18 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	clear_leaks(t_start *start)
{
	t_stack	*to_free;
	t_stack	*next;

	free(start->operations_to_do);
	free(start->operations_tmp);
	free(start->data);
	to_free = start->list_a;
	while (to_free != NULL)
	{
		next = to_free->next;
		free(to_free);
		to_free = next;
	}
	to_free = start->list_b;
	while (to_free != NULL)
	{
		next = to_free->next;
		free(to_free);
		to_free = next;
	}
	free(start);
}

void	clear_leaks_2(t_start *start)
{
	t_stack	*to_free;
	t_stack	*next;

	free(start->data);
	to_free = start->list_a;
	while (to_free != NULL)
	{
		next = to_free->next;
		free(to_free);
		to_free = next;
	}
	to_free = start->list_b;
	while (to_free != NULL)
	{
		next = to_free->next;
		free(to_free);
		to_free = next;
	}
	free(start);
}
