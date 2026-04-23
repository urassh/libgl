#include "libgl.h"

t_wire_rect	gl_create_wire_rect(t_vec3 origin, t_vec3 size)
{
	t_wire_rect	rect;

	rect.origin = origin;
	rect.size = size;
	rect.color = gl_black();
	rect.transform.rotation = gl_vec3(0, 0, 0);
	rect.transform.offset = gl_vec3(0, 0, 0);
	rect.transform.scale = gl_vec3(1, 1, 1);
	return (rect);
}
