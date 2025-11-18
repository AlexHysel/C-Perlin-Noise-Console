#include "hpn.h"
#include <stdio.h>
#include <unistd.h>

static void	repeat_char(char ch, int times)
{
	while (times > 0)
	{
		printf("%c", ch);
		times--;
	}
}

static int get_2d_y(short **str)
{
	int	y = 0;

	while (str[y])
		y++;
	return (y);
}

static int get_2d_x(short **str)
{
	int	x = 0;

	while (str[0][x])
		x++;
	return (x);
}

static int get_len(char *str)
{
	int	len = 0;

	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

static void	print_header(char *str, int width)
{
	int half_len = (width - get_len(str)) / 2;

	repeat_char('=', half_len);
	if (str)
		printf("%s", str);
	repeat_char('=', half_len);
	printf("\n");
}

void	display_grid(short **grid)
{
	int	len = get_2d_x(grid) * 4;
	print_header(" GRID ", len);

	for (int y = 0; grid[y]; y++)
	{
		for (int x = 0; grid[y][x]; x++)
			printf("%4d", grid[y][x]);
		printf("\n");
	}

	print_header(NULL, len);
}

void	print_noise_char(float noise)
{
	int	charset_len;
	int	index;

	noise += 1.0;
	charset_len = get_len(CHARSET);
	index = noise / 2 * (charset_len - 1);
	printf("%c", CHARSET[index]);
}

void	display_noise(float step, short **grid)
{
	int	width;
	int	height;

	width = get_2d_x(grid);
	height = get_2d_y(grid);

	print_header(" NOISE ", (width - 1) / step);
	
	for (float y = 0; y < height - 1; y += step)
	{
		for (float x = 0; x < width - 1; x += step)
			print_noise_char(perlin_noise(x, y, grid));
		printf("\n");
	}
	print_header(NULL, (width - 1) / step);
}
