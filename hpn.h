//Perlin Noise by AlexHysel

#ifndef HYSEL_PERLIN_NOISE_H
# define HYSEL_PERLIN_NOISE_H
# ifndef CHARSET
#  define CHARSET " `.:,^=;>+!*\?J7#%&@"
# endif

/*
 `.:,^=;>+!*\?J7#%&@
*/

# include <stdlib.h>
# include <math.h>

//Perlin noise

typedef struct s_cell
{
	short	ur;
	short	ul;
	short	br;
	short	bl;
}	t_cell;

float	perlin_noise(float x, float y, short **grid);

//Math functions
short	random_angle();
float	dot_product(float displacement_x, float displacement_y, short angle);
float	lerp(float t, float x, float y);

//Display
void	display_grid(short **grid);
void	print_noise_char(float noise);
void	display_noise(float step, short **grid);

//Grid
short	**create_grid(unsigned int width, unsigned int height);
t_cell	*get_cell(int x, int y, short **grid);
void	increment_grid_angles(short **grid, int value);

#endif
