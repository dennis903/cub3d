/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:01:46 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/10 17:01:46 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tem1;
	unsigned char	*tem2;

	i = 0;
	tem1 = (unsigned char *)s1;
	tem2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (tem1[i] == tem2[i] && tem1[i] != '\0' && tem2[i] != '\0' && i < n)
		i++;
	if (tem1[i] != '\0' && tem2[i] != '\0' && i == n)
		return (0);
	return ((int)(tem1[i] - tem2[i]));
}
