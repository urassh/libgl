#include <string.h>
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
	strlcpy(rect.label, "rect", GL_LABEL_MAX);
	return (rect);
}

t_rect	gl_create_rect_with_label(t_vec3 origin, t_vec3 size,
			const char *label)
{
	t_rect	rect;

	rect = gl_create_rect(origin, size);
	strlcpy(rect.label, label, GL_LABEL_MAX);
	return (rect);
}
