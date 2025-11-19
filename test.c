#include <stdio.h>
#include "hpn.h"
#include <time.h>

int	main(int argc, char *args[])
{
	if (argc < 2)
	{
		printf("Not enough params. [seed], optional: [grid width (>= 2)] [grid height (>= 2)]");
		return (-1);
	}
	unsigned int	seed = atoi(args[1]);
	short			w = 2;
	short			h = 2;
	short			**grid;
	struct timespec delay;

	if (args >= 3)
		w = atoi(args[2]);
	if (args >= 4)
		h = atoi(args[3]);

	srand(seed);
	grid = create_grid(w, h);

    delay.tv_sec = 0;
    delay.tv_nsec = 100000000;
	
	printf("\n");
	while(1)
	{
		display_noise(0.02, grid);
		printf("\n");
		increment_grid_angles(grid, 1);
		nanosleep(&delay, NULL);
	}
}
