#include "libgl.h"

void	gl_color_cube(t_cube *cube, t_color color)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		cube->colors[i] = color;
		i++;
	}
}
