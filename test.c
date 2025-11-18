#include <stdio.h>
#include "hpn.h"
#include <time.h>

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

	struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 100000000;

	grid = create_grid(w, h);
	//display_grid(grid);
	
	printf("\n");
	while(1)
	{
		display_noise(0.02, grid);
		for (int i = 0; grid[i]; i++)
		{
			for (int d = 0; grid[i][d]; d++)
				grid[i][d] = (grid[i][d] + 1) % 360 + 1;
		}
		printf("\n");
		nanosleep(&delay, NULL);
	}
}
