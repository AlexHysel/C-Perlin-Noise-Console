#include "hpn.h"
#include <stdio.h>
static float	angle_in_cell(float x, float y)
{
	return ((float) atan2(y, x) / M_PI * 180);
}

static float	interpolate(t_cell *cell, float angle, float x, float y)
{
	float	ur = cos_similarity(cell->ur, angle);
	float	ul = cos_similarity(cell->ul, angle);
	float	br = cos_similarity(cell->br, angle);
	float	bl = cos_similarity(cell->bl, angle);

	//x = 6 * pow(x, 5) - 15 * pow(x, 4) + 10 * pow(x, 3);
	//y = 6 * pow(y, 5) - 15 * pow(y, 4) + 10 * pow(y, 3);

	float	inter_top = lerp(x, ul, ur);
	float	inter_bottom = lerp(x, bl, br);
	return (lerp(y, inter_top, inter_bottom));
}

float	perlin_noise(float x, float y, short **grid)
{
	t_cell	*cell;
	float	angle;
	int		cell_x;
	int		cell_y;
	
	cell_x = floor(x);
	cell_y = floor(y);
	x = x - cell_x;
	y = y - cell_y;

	cell = find_cell(cell_x, cell_y, grid);
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

t_cell	*find_cell(int x, int y, short **grid)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));

	cell->ul = grid[y][x];
	cell->ur = grid[y][x + 1];
	cell->bl = grid[y + 1][x];
	cell->br = grid[y + 1][x + 1];
	return (cell);
}
