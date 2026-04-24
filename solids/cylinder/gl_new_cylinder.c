#include <string.h>
#include "libgl.h"

t_cylinder	gl_new_cylinder(t_vec3 origin, float radius, float height,
				int slices)
{
	t_cylinder	cyl;

	strlcpy(cyl.label, "cylinder", GL_LABEL_MAX);
	cyl.origin = origin;
	cyl.radius = radius;
	cyl.height = height;
	cyl.slices = slices;
	cyl.color = gl_black();
	cyl.has_outline = false;
	cyl.transform.rotation = gl_vec3(0, 0, 0);
	cyl.transform.offset = gl_vec3(0, 0, 0);
	cyl.transform.scale = gl_vec3(1, 1, 1);
	return (cyl);
}

t_cylinder	gl_new_cylinder_with_label(t_vec3 origin, float radius,
				float height, int slices, const char *label)
{
	t_cylinder	cyl;

	cyl = gl_new_cylinder(origin, radius, height, slices);
	if (strlen(label) < GL_LABEL_MAX)
		strlcpy(cyl.label, label, GL_LABEL_MAX);
	return (cyl);
}
