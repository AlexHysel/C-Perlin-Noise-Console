#include <stdio.h>
#include "hpn.h"
#include <time.h>

int	main(int argc, char *args[])
{
	if (argc < 2)
	{
		printf("Not enough params. [seed] \nOptional: [grid width (>= 2)] [grid height (>= 2)] [display step (> 0.0, default is 0.02)]");
		return (-1);
	}
	unsigned int	seed = atoi(args[1]);
	short			w = 2;
	short			h = 2;
	float			display_step = 0.02;
	short			**grid;
	struct timespec delay;

	if (argc >= 3)
		w = atoi(args[2]);
	if (argc >= 4)
		h = atoi(args[3]);
	if (argc >= 5)
		display_step = atof(args[4]);

	if (w < 2)
		printf("Wrong param [width] (%d)", w);
	else if (h < 2)
		printf("Wrong param [height] (%d)", h);
	else if (display_step <= 0.0)
		printf("Wrong param [display step] (%f)", display_step);
	else 
	{
		srand(seed);
		grid = create_grid(w, h);
	
		delay.tv_sec = 0;
		delay.tv_nsec = 100000000;

		printf("\n");
		while(1)
		{
			display_noise(display_step, grid);
			printf("\n");
			increment_grid_angles(grid, 1);
			nanosleep(&delay, NULL);
		}
	}
}
