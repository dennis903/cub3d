/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:18:46 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/18 15:29:41 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_abs(int n)
{
	return ((n < 0) ? (n * -1) : n);
}

int			numlen(int n)
{
	long	temp;
	int		count;

	if (n < 0)
		count = 1;
	else
		count = 0;
	temp = (long)ft_abs(n);
	while (n / 10)
	{
		count++;
		n /= 10;
	}
	return (count + 1);
}

char		*ft_itoa(int n)
{
	char	*temp;
	int		len;
	int		minus;

	len = numlen(n);
	minus = (n < 0) ? -1 : 1;
	if (!(temp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp[len--] = '\0';
	while (len >= 0)
	{
		temp[len] = ft_abs(n % 10) + '0';
		n = ft_abs(n / 10);
		len--;
	}
	if (minus == -1)
		temp[0] = '-';
	return (temp);
}
