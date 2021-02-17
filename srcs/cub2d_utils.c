#include "../cub3d.h"

double				normalize_angle(double ray_angle)
{
	ray_angle = fmod(ray_angle, PI * 2);
	if (ray_angle < 0)
		ray_angle = (PI * 2) + ray_angle;
	return (ray_angle);
}