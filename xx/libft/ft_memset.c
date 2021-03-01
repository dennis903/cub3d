/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:33:00 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/08 15:03:33 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*temp;

	if (!b)
	{
		temp = (char *)b;
		temp[0] = 0;
		return ((void *)temp);
	}
	temp = (char *)b;
	while (len--)
	{
		*temp = c;
		temp++;
	}
	return (b);
}
