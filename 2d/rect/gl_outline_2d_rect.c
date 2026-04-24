#include "libgl.h"

void	gl_outline_2d_rect(t_2d_rect *rect, t_color color)
{
	rect->has_outline = true;
	rect->outline_color = color;
}
