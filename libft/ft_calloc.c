/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:19:38 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/18 15:39:45 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	if (!(temp = malloc(count * size)))
		return (NULL);
	if (temp == 0)
		return (0);
	ft_bzero(temp, count * size);
	return (temp);
}
