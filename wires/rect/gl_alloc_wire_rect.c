#include <stdlib.h>
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
