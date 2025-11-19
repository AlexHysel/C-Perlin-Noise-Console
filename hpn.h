//Perlin Noise by AlexHysel

#ifndef HYSEL_PERLIN_NOISE_H
# define HYSEL_PERLIN_NOISE_H
# ifndef CHARSET
#  define CHARSET " `.,:;+!/?7J%&#@"
# endif
# ifndef CHAR_RATIO
#  define CHAR_RATIO 2.0
# endif

# include <stdlib.h>
# include <math.h>

//Perlin noise
float	perlin_noise(float x, float y, short **grid);

//Math functions
float	dot_product(float displacement_x, float displacement_y, short angle);
float	lerp(float t, float x, float y);
float	perlin_curve(float value);
float	quintic_curve(float valie);

//Display
void	display_grid(short **grid);
void	print_noise_char(float noise);
void	display_noise(float step, short **grid);

//Grid
typedef struct s_cell
{
	short	ur; //Upper-Right
	short	ul; //Upper-Left
	short	br; //Bottom-Right
	short	bl; //Bottom-Left
}	t_cell;

short	**create_grid(unsigned int width, unsigned int height);
t_cell	*get_cell(int x, int y, short **grid);
void	increment_grid_angles(short **grid, short value);

#endif
