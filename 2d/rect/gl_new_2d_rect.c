#include <string.h>
#include "libgl.h"

t_2d_rect	gl_new_2d_rect(t_vec2 origin, t_vec2 size)
{
	t_2d_rect	rect;

	rect.type = GL_TYPE_2D_RECT;
	strlcpy(rect.label, "2d_rect", GL_LABEL_MAX);
	rect.origin = origin;
	rect.size = size;
	rect.color = gl_black();
	rect.has_outline = false;
	rect.transform.rotation = 0;
	rect.transform.offset = gl_vec2(0, 0);
	rect.transform.scale = gl_vec2(1, 1);
	return (rect);
}

t_2d_rect	gl_new_2d_rect_with_label(t_vec2 origin, t_vec2 size,
				const char *label)
{
	t_2d_rect	rect;

	rect = gl_new_2d_rect(origin, size);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(rect.label, label, GL_LABEL_MAX);
	return (rect);
}
