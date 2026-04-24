#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_wire_rect	*gl_alloc_wire_rect(t_vec3 origin, t_vec3 size)
{
	t_wire_rect	*rect;

	rect = (t_wire_rect *)malloc(sizeof(t_wire_rect));
	if (!rect)
		return (NULL);
	*rect = gl_create_wire_rect(origin, size);
	return (rect);
}

t_wire_rect	*gl_alloc_wire_rect_with_label(t_vec3 origin, t_vec3 size,
				const char *label)
{
	t_wire_rect	*rect;

	rect = gl_alloc_wire_rect(origin, size);
	if (!rect)
		return (NULL);
	strlcpy(rect->label, label, GL_LABEL_MAX);
	return (rect);
}
