#include "hpn.h"

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

float	quintic_curve(float value)
{
	return (6 * pow(value, 5) - 15 * pow(value, 4) + 10 * pow(value, 3));
}

float	perlin_curve(float value)
{
	return (3 * pow(value, 2) - 2 * pow(value, 3));
}
