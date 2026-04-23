#include "libgl.h"

void	gl_outline_cylinder(t_cylinder *cyl, t_color color)
{
	cyl->has_outline = true;
	cyl->outline_color = color;
}
