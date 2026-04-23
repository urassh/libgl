#include "libgl.h"

void	gl_outline_cone(t_cone *cone, t_color color)
{
	cone->has_outline = true;
	cone->outline_color = color;
}
