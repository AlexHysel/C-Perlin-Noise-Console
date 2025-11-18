//Perlin Noise by AlexHysel

#ifndef HYSEL_PERLIN_NOISE_H
# define HYSEL_PERLIN_NOISE_H
# ifndef CHARSET
#  define CHARSET " `.-:^=;>+!*?J#%&@ "
# endif

# include <stdlib.h>
# include <math.h>

//perlin noise

typedef struct s_cell
{
	short	ur;
	short	ul;
	short	br;
	short	bl;
}	t_cell;

float	perlin_noise(float x, float y, short **grid);
short	**create_grid(unsigned int width, unsigned int height);
t_cell	*find_cell(int x, int y, short **grid);

//math functions
short	random_angle();
float	cos_similarity(short angle1, short angle2);
float	lerp(float t, float x, float y);

//display
void	display_grid(short **grid);
void	print_noise_char(float noise);
void	display_noise(float step, short **grid);
#endif
