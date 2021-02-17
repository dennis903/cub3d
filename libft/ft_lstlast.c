/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42student.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:26:53 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/13 22:31:01 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstlast(t_list *lst)
{
	t_list		*node;

	if (lst)
	{
		node = lst;
		while (1)
		{
			if (node->next == NULL)
				return (node);
			node = node->next;
		}
	}
	return (NULL);
}
