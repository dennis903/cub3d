/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:49:12 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/12 21:49:13 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double				normalize_angle(double ray_angle)
{
	ray_angle = fmod(ray_angle, PI * 2);
	if (ray_angle < 0)
		ray_angle = (PI * 2) + ray_angle;
	return (ray_angle);
}