#include "hpn.h"
#include <stdio.h>

static float	increase_contrast(float noise)
{
	if (noise < 0.0)
		return (-powf(-noise, 0.35));
	return (powf(noise, 0.35));
}

static float	interpolate(t_cell *cell, float x, float y)
{
	float	ul = dot_product(x, y, cell->ul);
	float	ur = dot_product(x - 1, y, cell->ur);
	float	bl = dot_product(x, y - 1, cell->bl);
	float	br = dot_product(x - 1, y - 1, cell->br);

	x = perlin_curve(x);
	y = perlin_curve(y);

	float	inter_top = lerp(x, ul, ur);
	float	inter_bottom = lerp(x, bl, br);
	float	noise = lerp(y, inter_top, inter_bottom);
	return (increase_contrast(noise));
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
