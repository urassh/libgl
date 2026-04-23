#include "libgl.h"

t_color	gl_color(float r, float g, float b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}
