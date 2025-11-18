#include "hpn.h"

short	random_angle()
{
	return (rand() % 360);
}

float	cos_similarity(short angle1, short angle2)
{
	short	angle_between;

	if (angle1 < angle2)
		angle_between = angle2 - angle1;
	else
		angle_between = angle1 - angle2;
	
	return (cos(angle_between * M_PI / 180));
}

float	lerp(float t, float a, float b)
{
	return ((t - 1) * a + t * b);
}
