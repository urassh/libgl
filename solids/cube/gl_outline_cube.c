#include "libgl.h"

void	gl_outline_cube(t_cube *cube, t_color color)
{
	cube->has_outline = 1;
	cube->outline_color = color;
}
