#include "hpn.h"
#include <stdio.h>

static float	angle_in_cell(float x, float y, float x1, float y1)
{
	return ((float) atan2(y - y1, x - x1) / M_PI * 180);
}

static float	interpolate(t_cell *cell, float x, float y)
{
	float	ul = dot_product(x, y, cell->ul);
	float	ur = dot_product(x - 1, y, cell->ur);
	float	bl = dot_product(x, y - 1, cell->bl);
	float	br = dot_product(x - 1, y - 1, cell->br);

	x = 6 * pow(x, 5) - 15 * pow(x, 4) + 10 * pow(x, 3);
	y = 6 * pow(y, 5) - 15 * pow(y, 4) + 10 * pow(y, 3);

	float	inter_top = lerp(x, ul, ur);
	float	inter_bottom = lerp(x, bl, br);
	return (lerp(y, inter_top, inter_bottom));
}

float	perlin_noise(float x, float y, short **grid)
{
	t_cell	*cell;
	int		cell_x;
	int		cell_y;
	
	cell_x = floor(x);
	cell_y = floor(y);
	x = x - cell_x;
	y = y - cell_y;

	cell = get_cell(cell_x, cell_y, grid);
	return (interpolate(cell, x, y));
}
