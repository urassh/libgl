#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_wire_cone	*gl_alloc_wire_cone(t_vec3 origin, float radius, float height)
{
	t_wire_cone	*cone;

	cone = (t_wire_cone *)malloc(sizeof(t_wire_cone));
	if (!cone)
		return (NULL);
	*cone = gl_create_wire_cone(origin, radius, height);
	return (cone);
}

t_wire_cone	*gl_alloc_wire_cone_with_label(t_vec3 origin, float radius,
				float height, const char *label)
{
	t_wire_cone	*cone;

	cone = gl_alloc_wire_cone(origin, radius, height);
	if (!cone)
		return (NULL);
	strlcpy(cone->label, label, GL_LABEL_MAX);
	return (cone);
}
