/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:12:00 by jmayou            #+#    #+#             */
/*   Updated: 2024/11/22 15:42:56 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_node(t_list *list)
{
	t_dir	*red;

	free_arr(list->command);
	list->command = NULL;
	while (list->redir)
	{
		red = list->redir;
		list->redir = list->redir->next;
		red->type = 0;
		free(red->file_name);
		red->file_name = NULL;
		free(red);
		red = NULL;
	}
	list->next = NULL;
}

void	free_list(t_list *list)
{
	t_list	*lst;

	while (list)
	{
		lst = list;
		list = list->next;
		free_node(lst);
		free(lst);
		lst = NULL;
	}
}

void	free_for_can_replace(char **tmp, char **tmp1, char **sub)
{
	free((*sub));
	free((*tmp));
	free((*tmp1));
}

void	*free_arry(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}
