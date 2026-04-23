#include "libgl.h"

void	gl_outline_rect(t_rect *rect, t_color color)
{
	rect->has_outline = 1;
	rect->outline_color = color;
}
