#include <string.h>
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
	strlcpy(rect.label, "wire_rect", GL_LABEL_MAX);
	return (rect);
}

t_wire_rect	gl_create_wire_rect_with_label(t_vec3 origin, t_vec3 size,
				const char *label)
{
	t_wire_rect	rect;

	rect = gl_create_wire_rect(origin, size);
	strlcpy(rect.label, label, GL_LABEL_MAX);
	return (rect);
}
