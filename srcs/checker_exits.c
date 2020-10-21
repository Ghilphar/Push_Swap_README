/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:14:27 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/05 19:40:07 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_exit_success(t_start *start)
{
	t_stack		*tmp;
	t_stack		*tmp_2;

	free(start->data);
	tmp = start->list_a;
	while (tmp != NULL)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
		free(tmp_2);
	}
	tmp = start->list_b;
	while (tmp != NULL)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
		free(tmp_2);
	}
	start->list_a = NULL;
	start->list_b = NULL;
	free(start);
	ft_printf("OK\n");
	exit(EXIT_SUCCESS);
}

void	ft_exit_failure(t_start *start)
{
	t_stack		*tmp_2;
	t_stack		*tmp;

	free(start->data);
	tmp = start->list_a;
	while (tmp != NULL)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
		free(tmp_2);
	}
	tmp = start->list_b;
	while (tmp != NULL)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
		free(tmp_2);
	}
	start->list_a = NULL;
	start->list_b = NULL;
	free(start);
	ft_printf("KO\n");
	exit(EXIT_FAILURE);
}

void	ft_exit_error(t_start *start)
{
	t_stack		*tmp;
	t_stack		*tmp_2;

	free((start->data));
	tmp = start->list_a;
	while (tmp != NULL)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
		free(tmp_2);
	}
	tmp = start->list_b;
	while (tmp != NULL)
	{
		tmp_2 = tmp;
		tmp = tmp->next;
		free(tmp_2);
	}
	start->list_a = NULL;
	start->list_b = NULL;
	free(start);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	exit_gnl(t_start *start, char **l)
{
	free(*l);
	free(l);
	ft_exit_error(start);
}
