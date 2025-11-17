#include "hpn.h"

static float	angle_in_cell(float x, float y)
{
	x = x - (int) x;
	y = y - (int) y;
	return ((float) atan2(y, x) / M_PI * 180);
}

static float	interpolate(t_cell *cell, float angle, float x, float y)
{
	float	ur = cos_similarity(cell->ur, angle);
	float	ul = cos_similarity(cell->ul, angle);
	float	br = cos_similarity(cell->br, angle);
	float	bl = cos_similarity(cell->bl, angle);

	//Original funcion by Perlin
	float	t_x = 6 * pow(x, 5) - 15 * pow(x, 4) + 10 * pow(x, 3);
	float	t_y = 6 * pow(y, 5) - 15 * pow(y, 4) + 10 * pow(y, 3);

	float	inter_top = lin_interpolation(t_x, ul, ur);
	float	inter_bottom = lin_interpolation(t_x, ul, ur);
	return (lin_interpolation(t_y, inter_top, inter_bottom));
}

float	perlin_noise(float x, float y, short **grid)
{
	if (x < 0)
		x * -1;
	if (y < 0)
		y * -1;

	t_cell	*cell;
	float	angle;

	cell = find_cell(x, y, grid);
	angle = angle_in_cell(x, y);

	return (interpolate(cell, angle, x, y));
}

short	**create_grid(unsigned int width, unsigned int height)
{
	short			**grid;

	if (!width || !height)
		return (NULL);
	grid = malloc((height + 1) * sizeof(short *));
	grid[height] = NULL;
	while(height-- > 0)
	{
		grid[height] = malloc((width + 1) * sizeof(short));
		grid[height][width] = 0;
		for (int w = width - 1; w >= 0; w--)
			grid[height][w] = random_angle();
	}
	return (grid);
}

t_cell	*find_cell(float x, float y, short **grid)
{
	t_cell	*cell;
	short	x2;
	short	y2;

	cell = malloc(sizeof(t_cell));

	x2 = x;
	y2 = y;
	cell->ul = grid[y2][x2];
	cell->ur = grid[y2][x2 + 1];
	cell->bl = grid[y2 + 1][x2];
	cell->br = grid[y2 + 1][x2 + 1];
	return (cell);
}
