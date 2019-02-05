/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 01:55:43 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/22 06:52:24 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *temp;

	if (!(temp = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (!content)
	{
		temp->content = (void *)0;
		temp->content_size = 0;
	}
	else
	{
		if (!(temp->content = malloc(content_size)))
			return (NULL);
		ft_memmove(temp->content, content, content_size);
		temp->content_size = content_size;
	}
	temp->next = 0;
	return (temp);
}
