#include <string.h>
#include "libgl.h"

t_rect	gl_new_rect(t_vec3 origin, t_vec3 size)
{
	t_rect	rect;

	rect.type = GL_TYPE_RECT;
	strlcpy(rect.label, "rect", GL_LABEL_MAX);
	rect.origin = origin;
	rect.size = size;
	rect.color = gl_black();
	rect.has_outline = false;
	rect.transform.rotation = gl_vec3(0, 0, 0);
	rect.transform.offset = gl_vec3(0, 0, 0);
	rect.transform.scale = gl_vec3(1, 1, 1);
	return (rect);
}

t_rect	gl_new_rect_with_label(t_vec3 origin, t_vec3 size,
			const char *label)
{
	t_rect	rect;

	rect = gl_new_rect(origin, size);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(rect.label, label, GL_LABEL_MAX);
	return (rect);
}
