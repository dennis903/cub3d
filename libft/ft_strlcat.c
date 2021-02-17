/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:06:08 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/10 15:58:59 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	int		i;
	int		j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = dst_len;
	while (src[i] && 0 < (int)(size - i - dst_len - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	if (size < dst_len)
		return (src_len + size);
	else
	{
		dst[j] = 0;
		return (src_len + dst_len);
	}
}
