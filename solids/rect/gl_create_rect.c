#include "libgl.h"

t_rect	gl_create_rect(t_vec3 origin, t_vec3 size)
{
	t_rect	rect;

	rect.origin = origin;
	rect.size = size;
	rect.color = gl_black();
	rect.has_outline = false;
	rect.transform.rotation = gl_vec3(0, 0, 0);
	rect.transform.offset = gl_vec3(0, 0, 0);
	rect.transform.scale = gl_vec3(1, 1, 1);
	return (rect);
}
