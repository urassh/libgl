#include <stdlib.h>
#include <string.h>
#include "libgl.h"

t_cylinder	*gl_alloc_cylinder(t_vec3 origin, float radius, float height,
				int slices)
{
	t_cylinder	*cyl;

	cyl = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cyl)
		return (NULL);
	*cyl = gl_create_cylinder(origin, radius, height, slices);
	return (cyl);
}

t_cylinder	*gl_alloc_cylinder_with_label(t_vec3 origin, float radius,
				float height, int slices, const char *label)
{
	t_cylinder	*cyl;

	cyl = gl_alloc_cylinder(origin, radius, height, slices);
	if (!cyl)
		return (NULL);
	strlcpy(cyl->label, label, GL_LABEL_MAX);
	return (cyl);
}
