#include "hpn.h"

short	random_angle()
{
	return (rand() % 360);
}

float	dot_product(float displacement_x, float displacement_y, short angle)
{
	float	angle_rad = (float) angle / 180.0 * M_PI;
	float	grad_x = cos(angle_rad);
	float	grad_y = sin(angle_rad);

	return (grad_x * displacement_x + grad_y * displacement_y);
}

float	lerp(float t, float a, float b)
{
	return (a + t * (b - a));
}
