#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_wire_cylinder	*gl_alloc_wire_cylinder(t_vec3 origin, float radius,
					float height)
{
	t_wire_cylinder	*cyl;

	cyl = (t_wire_cylinder *)malloc(sizeof(t_wire_cylinder));
	if (!cyl)
		return (NULL);
	*cyl = gl_new_wire_cylinder(origin, radius, height);
	return (cyl);
}

t_wire_cylinder	*gl_alloc_wire_cylinder_with_label(t_vec3 origin, float radius,
					float height, const char *label)
{
	t_wire_cylinder	*cyl;

	cyl = gl_alloc_wire_cylinder(origin, radius, height);
	if (!cyl)
		return (NULL);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cyl->label, label, GL_LABEL_MAX);
	return (cyl);
}
