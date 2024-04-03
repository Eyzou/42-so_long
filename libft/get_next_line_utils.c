/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:34:17 by ehamm             #+#    #+#             */
/*   Updated: 2024/03/12 09:26:13 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_lstlastgnl(t_gnl *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	dealloc(t_gnl **list, t_gnl *clean_node, char *buf)
{
	t_gnl	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}

int	find_new_line(t_gnl *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	copy(t_gnl *list, char *dest)
{
	int	i;
	int	j;

	j = 0;
	if (NULL == list)
		return ;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				dest[j++] = '\n';
				dest[j] = '\0';
				return ;
			}
			dest[j++] = list->content[i++];
		}
		list = list->next;
	}
	dest[j] = '\0';
}

int	len_to_new_line(t_gnl *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}
