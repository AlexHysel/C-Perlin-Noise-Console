#include <stdio.h>
#include "hpn.h"

int	main(int argc, char *args[])
{
	unsigned int	seed;

	if (argc > 1)
		seed = atoi(args[1]);
	else
		seed = 0;

	srand(seed);
	short	**grid;
	short	w = atoi(args[2]);
	short	h = atoi(args[3]);

	grid = create_grid(w, h);
	display_grid(grid);
	
	printf("\n");
	for (float y = 0; y <= 2; y += 0.1)
	{
		for (float x = 0; x <= 2; x += 0.1)
			printf("%1f", perlin_noise(x, y, grid));
		printf("\n");
	}
}
