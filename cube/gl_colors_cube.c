#include "libgl.h"

void	gl_colors_cube(t_cube *cube, t_color colors[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		cube->colors[i] = colors[i];
		i++;
	}
}
