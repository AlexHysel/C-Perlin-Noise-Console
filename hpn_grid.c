#include "hpn.h"

static short	random_angle()
{
	return (rand() % 360);
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

t_cell	*get_cell(int x, int y, short **grid)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));

	cell->ul = grid[y][x];
	cell->ur = grid[y][x + 1];
	cell->bl = grid[y + 1][x];
	cell->br = grid[y + 1][x + 1];
	return (cell);
}

void	increment_grid_angles(short **grid, short value)
{
	for (int y = 0; grid[y]; y++)
		for (int x = 0; grid[y][x]; x++)
			grid[y][x] = (grid[y][x] + value) % 360 + 1;
}
